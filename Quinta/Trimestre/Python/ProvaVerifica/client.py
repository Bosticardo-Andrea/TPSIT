import socket,os
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(("127.0.0.1",5000))
def Uno():
    film = input("Che film vuoi chiedere: ").lower()
    s.sendto(("".join(["1","|",film])).encode(),("127.0.0.1",5000))
    os.system("cls")
    rec = s.recvfrom(4096)[0].decode()
    print(rec + "\n\n")
def Due():
    film = input("Di quale film vuoi conoscere i frammenti: ").lower()
    s.sendto("".join(["2","|",film]).encode(),("127.0.0.1",5000))
    os.system("cls")
    rec = s.recvfrom(4096)[0].decode()
    print(rec + "\n\n")
def Tre():
    film = input("Di quale film vuoi conoscere i frammenti: ").lower()
    s.sendto("".join(["3","|",film]).encode(),("127.0.0.1",5000))
    rec = s.recvfrom(4096)[0].decode()
    print(rec)
    nFrammento = input("Di quale frammento vuoi conoscere IP: ").lower()
    s.sendto(nFrammento.encode(),("127.0.0.1",5000))
    os.system("cls")
    rec = s.recvfrom(4096)[0].decode()
    print(rec + "\n\n")
def Quattro():
    film = input("Di quale film vuoi conoscere tutti gli hosst: ").lower()
    s.sendto(("".join(["4","|",film])).encode(),("127.0.0.1",5000))
    os.system("cls")
    rec = s.recvfrom(4096)[0].decode()
    print(rec + "\n\n")
dizio = {1:Uno,2:Due,3:Tre,4:Quattro}
rec = s.recvfrom(4096)[0].decode()
rec = rec.split(",")
rec = "".join(rec)
rec = rec.split(" ")
print("File disponibili:")
print("\n")
while True:
    print("\nScegli tra le seguenti opzioni: ")
    print("1. Conoscere se un file esiste")
    print("2. Sapere il numero di frammenti")
    print("3. Sapere l'IP di un host")
    print("4. Sapere tutti gli IP di un film\n")
    try:
        scelta = int(input("scegli un opzione: "))
        while scelta > 4 or scelta < 0:
            print("Scelta errata")
            scelta = int(input("scegli un opzione: "))
    except:
        print("Errore")
    os.system("cls")
    for x in rec: print(f"- {x[1:-1]}")
    print()
    dizio[scelta]()

    