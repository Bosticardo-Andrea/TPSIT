import sqlite3,time,socket
from threading import Thread
db = sqlite3.connect("./file.db")
cur = db.cursor()
res = cur.execute("SELECT nome,tot_frammenti\nFROM files")
dati = dict(res.fetchall())
res = cur.execute("SELECT *\nFROM files")
dizioFilm = {x[1]:int(x[2]) for x in [list(x) for x in res.fetchall()]}
res = cur.execute("SELECT *\nFROM frammenti")
lista = res.fetchall()
prov,listaFrammenti,prec,i,listaFilm = [],[],lista[0][2],0,list(dizioFilm.keys())
for x in lista:
    x = list(x)
    if x[1] == prec:
        x[1] = dizioFilm[listaFilm[i]]
        prov.append(x[1:])
    else:
        i+=1
        listaFrammenti.append(prov)
        prec = x[1]
        x[1] = dizioFilm[listaFilm[i]]
        prov = []
        prov.append(x[1:])
listaFrammenti.append(prov)
dizionario = {x:list(listaFrammenti[i]) for i,x in enumerate(dizioFilm)}
class MyThread(Thread):
    def __init__(self,s,connection,address):
        Thread.__init__(self)
        self.s = s
        self.running = True
        self.connection = connection
        self.address = address
    def run(self):
        print("sto ascoltando")
        self.connection.sendall(str(list(dizioFilm.keys()))[1:-1].encode())
        while self.running:
            dati = self.connection.recv(4096).decode().split("|")
            print(dati)
            if int(dati[0]) == 1:
                if dati[1] in dizionario.keys():
                    self.connection.sendall(f"Esiste il film {dati[1]}".encode())
                else:
                    self.connection.sendall((f"Non esiste il film {dati[1]}").encode())
            elif int(dati[0]) == 2:
                if dati[1] in dizionario.keys():
                    self.connection.sendall(f"Il film {dati[1]} ha {dizionario[dati[1]][0][0]} frammenti".encode())
                else:
                    self.connection.sendall((f"Non esiste il film {dati[1]}").encode())
            elif int(dati[0]) == 3:
                if dati[1] in dizioFilm.keys():
                    self.connection.sendall(f"Il film {dati[1]} ha {dizionario[dati[1]][0][0]} frammenti".encode())
                    fr = int(self.connection.recv(4096).decode())
                    self.connection.sendall(f"Il frammento {fr} é salvato nel pc con indirizzo IP: {dizionario[dati[1]][int(fr)-1][2]}".encode())
                else:
                    self.connection.sendall((f"Non esiste il film {dati[1]}").encode())
            elif int(dati[0]) == 4:
                if dati[1] in dizioFilm.keys():
                    stringa = f"Gli IP di tutti i pacchetti di {dati[1]} sono:\n"
                    for x in dizionario[dati[1]]:
                        stringa += f"{x[1]} - {x[2]}\n"
                    self.connection.sendall(stringa.encode())
                else:
                    self.connection.sendall((f"Non esiste il film {dati[1]}").encode())
    def stop(self):
        self.running = False
def main():
    s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    s.bind(("127.0.0.1",5000))
    s.listen()
    dizio,thread = {},[]
    while 1:
        print("In attesa di conessione...")
        connection,address = s.accept()
        dizio[address[0]] = connection
        thread.append(MyThread(s,connection,address))
        thread[-1].start()
    for i in thread: i.close()

if __name__=="__main__":
    main()