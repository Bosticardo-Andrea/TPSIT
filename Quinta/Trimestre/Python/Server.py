import sqlite3,socket
from threading import Thread
#leggo il database
db = sqlite3.connect("./operations.db")
cur = db.cursor()
#faccio una query per ricere i dati corretti dal database
res = cur.execute("SELECT client,operation\nFROM operations")
dati = res.fetchall()
#inserisco in una lista le operazioni
lista = [[x[0],x[1]] for x in dati]
#inserisco nel dizionario: key = id_client, value = una lista di tutte le operazioni
dizio = {x:[y[1] for y in lista if y[0]==x] for x in list(set([x[0] for x in lista]))}
#classe thread per i client
class MyThread(Thread):
    def __init__(self,s,connection,address,id):
        Thread.__init__(self)
        self.s = s #oggetto socket
        self.running = True # variabile per fermare il thread
        self.connection = connection # oggetto connessione
        self.address = address # address[0] = ip, address[1] = porta
        self.id = id # id del client 
    def run(self):
        while self.running: # controllo se posso continuare l'esecuzione
            for x in dizio[self.id]:# ciclo per la lista delle operazione da fare. dizio[id del client] = mi restituisce una lista di stringhe
                self.connection.sendall(x.encode())# invio la prima operazione 
                dati = self.connection.recv(4096).decode() # attendo la risposta da client
                print(f"{x} = {dati} from {self.address[0]} - {self.address[1]}") # stampo la risposta print (f"{operazione} = {risultato} from {client_ip} - {client_port}")
            self.connection.sendall("exit".encode()) # se ho finito il cliclo sulle operazioni invio il codice exit per far chiuidere il client
            self.stop()# fermo il thread
    def stop(self):
        self.running = False
def main():
    s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    s.bind(("127.0.0.1",5000))
    s.listen()
    #lista di thread e id che parte da 1
    thread,id = [],1
    while 1:
        #controllo che ci sia un thread (un client) per ogni id_client 
        if len(thread) == len(dizio):
            ok = True
            #ciclo finché tutti i thread non si sono fermati
            while ok:
                # ciclo sulla lista dei thread
                for i in thread:
                    #controllo che sia tutti chiusi
                    if i[1].running != False:ok = True
                    else: ok = False
            # esco del while True 
            break
        # attendo una connessione e la accetto, mi salvo la connection e l'address
        connection,address = s.accept()
        #aggiungo il Thread alla lista con il corrispettivo id
        thread.append([id,MyThread(s,connection,address,id)])
        #aggiorno l'id
        id += 1
        #faccio partire l'ultimo Thread inserito nella lista
        thread[-1][1].start()
    #chiudo in modo pulito tutti i thread
    for i in thread:
        i[1].join()

if __name__=="__main__":
    main()