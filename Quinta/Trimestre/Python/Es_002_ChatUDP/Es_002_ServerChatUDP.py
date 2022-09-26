import socket
s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind(("192.168.0.120",5000))
def letturaFilePerNome():
    f = open("dati.txt","r")
    righe = f.readlines()
    f.close()
    dizio={}
    for x in righe[1:]:
        nomeIP = x.split(",")
        dizio[nomeIP[0]] = nomeIP[1][:-1]
    return dizio
def get_key(val,dizio): 
    for key, value in dizio.items():
        if val == value:return key
    return None
while True:
    dati,address= s.recvfrom(4096)
    print(f"\n{dati.decode()}\t inviato da: {address}")
    if "|" in dati.decode():
        s.sendto("Errore di scrittura del messaggio".encode(),(address[0],5000))
    else:
        stringa = dati.decode().split("|")
        dizio = letturaFilePerNome()
        if stringa[1] not in dizio:
            s.sendto("Destinatario non trovato".encode(),(address[0],5000))
        else:
            if get_key(address[0],dizio) != None:
                mex = f"{get_key(address[0],dizio)}-->{stringa[0]}"
                s.sendto(mex.encode(),(dizio[stringa[1]],5000))
            else: 
                mex = f"sconosciuto -->{stringa[0]}"
                s.sendto(mex.encode(),(dizio[stringa[1]],5000))
    