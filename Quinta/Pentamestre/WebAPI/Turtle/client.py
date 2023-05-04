import requests
def controllo(mov):
    while (mov <= 0 or (mov) > 5):
        mov = int(input("""Cosa vuoi fare: 
                            1. movimento in avanti di un numero arbitrario di pixel
                            2. rotazione a sinistra di un numero arbitrario di gradi
                            3. rotazione a destra di un numero arbitrario di gradi
                            4. vedi la tua cronologia
                            5. Esci
                            dato: """))
    return mov

def main():
    movimenti = {1:"avanti",2:"sx",3:"dx"}
    id = 2
    mov = 0 
    while mov != 5:
        mov = int(input("""Cosa vuoi fare: 
                            1. movimento in avanti di un numero arbitrario di pixel
                            2. rotazione a sinistra di un numero arbitrario di gradi
                            3. rotazione a destra di un numero arbitrario di gradi
                            4. vedi la tua cronologia
                            5. Esci
                            dato: """))
        mov = controllo(mov)
        if mov == 4:ris = requests.get(f"http://127.0.0.1:5000/cron?id={id}")
        else: ris =requests.get(f"http://127.0.0.1:5000/mov?id={id}&mov={movimenti[mov]}")
        print(ris.text)
        
        
if __name__=="__main__":main()