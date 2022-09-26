import socket
from threading import Thread
def get_key(val,dizioIPNome): 
    for key, value in dizioIPNome.items():
        if val == value:return key
    return None
def letturaFilePerIP():
    f = open("dati.txt","r")
    righe = f.readlines()
    f.close()
    dizioIPNome={}
    for x in righe[1:]:
        nomeIP = x.split(",")
        dizioIPNome[nomeIP[0]] = nomeIP[1][:-1]
    return dizioIPNome
class MyThread(Thread):
    def __init__(self,s,connection,address,nick):
        Thread.__init__(self)
        self.s = s
        self.running = True
        self.connection =connection
        self.address = address
        self.nick = nick
    def run(self):
        while self.running:
            print(f"{self.nick} sto ascoltando")
            dati = connection.recv(4096)
            print(f"\n{dati.decode()}\t inviato da: {self.address}")
            if "|" not in dati.decode():
                connection.sendall("Errore di scrittura del messaggio".encode())
            else:
                stringa = dati.decode().split("|")
                if stringa[1] not in dizioIPNome:
                    connection.sendall("Destinatario non trovato".encode())
                else:
                    if get_key(self.address[0],dizioIPNome) != None:
                        nome = get_key(self.address[0],dizioIPNome)
                        mex = f"{nome}-->{stringa[0]}"
                        #connection.sendall(mex.encode(),(dizioIPNome[stringa[1]],5000))
                        dizio[dizioIPNome[stringa[1]]].sendall(mex.encode())
                    else: 
                        mex = f"sconosciuto -->{stringa[0]}"
                        connection.sendall(mex.encode())
    def stop(self):
        self.running = False

thread,dizio,dizioIPNome = [],{},letturaFilePerIP()
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind(("0.0.0.0",5000))
s.listen()

while 1:
    print("In attesa di conessione...")
    connection,address = s.accept()
    if get_key(address[0],dizioIPNome) != None:
        print(f"{get_key(address[0],dizioIPNome)},{address[0]} sono connesso")
        dizio[address[0]] = connection
        thread.append(MyThread(s,connection,address,get_key(address[0],dizioIPNome)))
        thread[-1].start()
    else:
        connection.sendall("Errore".encode())
connection.close()