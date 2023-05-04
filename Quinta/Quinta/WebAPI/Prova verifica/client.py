import requests,json,os

def main():
    os.system("cls")
    #id = int(input("Inserisci l'id.\nAmessi[1/2]\nid: "))
    #print([client[0] for client in json.loads(requests.get(f"http://127.0.0.1:5000/ammessi").text)])
    ammessi = "".join([str(client[0]) for client in json.loads(requests.get(f"http://127.0.0.1:5000/ammessi").text)])
    id = int(input(f"Inserisci l'id.\nAmessi[{ammessi}]\nid: "))
    operazioni = requests.get(f"http://127.0.0.1:5000/operazioni?idU={id}")
    op = json.loads(operazioni.text)
    for exp in op:
        requests.get(f"http://127.0.0.1:5000/SalvaOperazioni",params={"idU":id,"ris":eval(exp[1]),"idO":exp[0]})

if __name__=="__main__":main()
