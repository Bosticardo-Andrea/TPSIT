import socket
from threading import Thread
class MyThread(Thread):
    def __init__(self):
        Thread.__init__(self)
        self.s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.s.bind(("0.0.0.0",5000))
        self.running = True
    def run(self):
        while self.running:
            dati,ind = self.s.recvfrom(4096)
            print(f"\n{dati.decode()}")
    def stop(self):
        self.running = False

def main():
    thread = MyThread()
    thread.start()
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    while True:
        dest = input("a chi vuoi mandare il messaggio? ")
        s.sendto("".join(input("tu--> ") + "|" + dest).encode(),("192.168.0.136",5000))

if __name__ == "__main__":
    main()