#cifarrio di Vernam
def get_key(val): 
    for key, value in dizioAlphaCN.items():
        if val == value:return key
    return None
def cifra(parola):
    return "".join(get_key((dizioAlphaCN[chiave[n]]+dizioAlphaCN[x])%len(dizioAlphaCN)) for n,x in enumerate(parola))
def decifra(parola):
    return "".join(get_key((dizioAlphaCN[x]-dizioAlphaCN[chiave[n]])%len(dizioAlphaCN)) for n,x in enumerate(parola))

chiave = "itisdelpozzo"
parola = input("Inserisci la parola: ").lower()
dizioAlphaCN = {chr(x): n for n,x in enumerate(range(97,123))}
print(cifra(parola),decifra(cifra(parola)))

