import Pile_Code as pc
c = pc.Coda()
c1 = pc.Coda()
p = pc.Pila()
n = int(input("Inserisci il numero di numeri: "))
for _ in range (n):
    c.enqueue(input("Cosa vuoi inserire: "))
    p.push(c.dequeue())
for _ in range(n):
    c1.enqueue(p.pop())
c1.print()