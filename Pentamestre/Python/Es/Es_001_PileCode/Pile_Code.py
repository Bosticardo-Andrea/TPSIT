class Pila():
    def __init__(self):
        self.pila=[]
        
    def push(self,elemento):
        self.pila.append(elemento)
    
    def pop(self):
        if len(self.pila) != 0:
            return self.pila.pop()
        else:
            return None
    
    def print(self): 
        print(self.pila)

class Coda():
    def __init__(self):
        self.coda=[]
        
    def enqueue(self,elemento):
        self.coda.append(elemento)
    
    def dequeue(self):
        if len(self.coda) != 0:
            return self.coda.pop(0)
        else:
            return None
    
    def print(self): 
        print(self.coda)

def main():
    p = Pila()
    p.push(1)
    p.push(2)
    x = p.pop()
    p.print()

    c = Coda()
    c.enqueue(5)
    c.enqueue(6)
    x = c.dequeue()
    c.print()

if __name__=="__main__":
    main()