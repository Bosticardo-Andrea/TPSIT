import socket
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
# mi connetto al server
s.connect(("127.0.0.1",5000))
while 1:
    # ricevo una stringa dal server e la decodifico in stringa
    rec = s.recvfrom(4096)[0].decode()
    # se ricevo exit esco dal while e chiudo la connessione
    if rec == "exit":
        s.close()
        break
    else:
        # provo a fare la eval in caso desse errore il try except cattura l'eccezione
        try:sol = eval(rec)
        except:pass
        # invio il risultato al server
        s.sendto(str(sol).encode(),("127.0.0.1",5000))

    