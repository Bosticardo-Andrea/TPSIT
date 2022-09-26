from re import L
from ssl import AlertDescription
from tkinter.messagebox import NO

def ReadCSV(albero):
    f = open("./dati.csv","r")
    righe = f.readlines()
    f.close()
    riga = []
    for el in righe:
        riga.append(el.split(";"))
    for i,el in enumerate(riga):
        albero.insertNode(el[0],el[1],int(el[2][:-1]))
class Node:
    def __init__(self,name,surname,number):
        self.number = number
        self.name = name
        self.surname = surname
        self.left = None #istanza nodo sinistro
        self.right = None #istanza nodo destro
    def printNode(self):
        print(self.number)
    def printTree(self):
        if self.left:
            self.left.printTree()
        if self.right:
            self.right.printTree()
        print(self.number)
    def returnDepth(self): #calcola il numero di passi per trovare la foglia piu distante
        if self.right:return  self.right.returnDepth()+1
        if self.left:return  self.left.returnDepth()+1
        else: return 0
    def calcDepth(self):#ritorna il ramo dell' albero dove ci sono più figli
        if self.left and self.right: return max(self.left.returnDepth(),self.right.returnDepth())+1 #se esistono entrambi i figli ritorna il massimo tra essi
        if self.left and not self.right: return self.left.returnDepth()+1 # esiste solo il
        if self.right and not self.left: return self.right.returnDepth()+1
        else: return 0
    def insertNode(self,name,surname,number):
        if self.number:
            if number < self.number:
                if self.left is None:
                    self.left = Node(name,surname,number)
                else:
                    self.left.insertNode(name,surname,number)
            elif number > self.number:
                if self.right is None:
                        self.right = Node(name,surname,number)
                else:
                    self.right.insertNode(name,surname,number)
        else:
            self.number = number   
    def cercaNodo(self,num):
        if num < self.number:
            self.left.cercaNodo(num)
        elif(num > self.number):
            self.right.cercaNodo(num)
        elif(num == self.number):
            print(self.number)   
def main():
    albero = Node(None,None,None)
    ReadCSV(albero)
if __name__ == "__main__":
    main()
