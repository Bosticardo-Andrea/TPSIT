from re import L
from ssl import AlertDescription
from tkinter.messagebox import NO


class Node:
    def __init__(self,value):
        self.value = value
        self.left = None #istanza nodo sinistro
        self.right = None #istanza nodo destro
    def printNode(self):
        print(self.value)
    def printTree(self):
        if self.left:
            self.left.printTree()
        if self.right:
            self.right.printTree()
        print(self.value)
    def returnDepth(self): #calcola il numero di passi per trovare la foglia piu distante
        if self.right:return  self.right.returnDepth()+1
        if self.left:return  self.left.returnDepth()+1
        else: return 0
    def calcDepth(self):#ritorna il ramo dell' albero dove ci sono più figli
        if self.left and self.right: return max(self.left.returnDepth(),self.right.returnDepth())+1 #se esistono entrambi i figli ritorna il massimo tra essi
        if self.left and not self.right: return self.left.returnDepth()+1 # esiste solo il
        if self.right and not self.left: return self.right.returnDepth()+1
        else: return 0
    def insertNode(self,value):
        if self.value:
            if value < self.value:
                if self.left is None:
                    self.left = Node(value)
                else:
                    self.left.insertNode(value)
            elif value > self.value:
                if self.right is None:
                        self.right = Node(value)
                else:
                    self.right.insertNode(value)
        else:
            self.value = value   
    def cercaNodo(self,num):
        if num < self.value:
            self.left.cercaNodo(num)
        elif(num > self.value):
            self.right.cercaNodo(num)
        elif(num == self.value):
            print(self.value)   
def main():
    albero = Node(None)
    albero.insertNode(60)
    albero.insertNode(70)
    albero.insertNode(50)
    albero.insertNode(34)
    albero.insertNode(55)
    albero.insertNode(23)
    albero.insertNode(36)
    
    #albero.printTree()
    print(albero.profonditaAlbero())
    #albero.cercaNodo(36)
if __name__ == "__main__":
    main()
