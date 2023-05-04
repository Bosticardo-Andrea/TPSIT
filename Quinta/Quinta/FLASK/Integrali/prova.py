from sympy import *
init_printing()
x = symbols('x')  # definiamo la variabile simbolica x
f = x**2 + 2*x + 1  # definiamo la funzione da integrare
a = 0  # definiamo il limite inferiore di integrazione
b = 1  # definiamo il limite superiore di integrazione

# Calcoliamo l'integrale definito di f rispetto a x tra a e b
result = integrate(f, (x, a, b))
print(latex(Integral(f,x)))
# Restituiamo il risultato
print(result)
