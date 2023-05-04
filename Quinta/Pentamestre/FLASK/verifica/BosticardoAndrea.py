from flask import Flask, render_template, request,redirect, url_for,make_response
from datetime import datetime
import hashlib,sqlite3,semaforo
# utente = admin 
# pass = 123
Semaforo = semaforo.semaforo()
app = Flask(__name__)

#Crea un digest 
def creaDigest(stringa:str)->str:
    hasher = hashlib.sha256()
    hasher.update(stringa.encode())
    hash_stringa = hasher.hexdigest()
    return hash_stringa

#controlla i digest del db e quelli inseriti nella pagina di login
def validate(username, password):
    correct = False
    con = sqlite3.connect('./dati.db')
    cur = con.cursor()
    cur.execute("SELECT * FROM utenti")
    rows = cur.fetchall()
    con.close()
    for row in rows:
        id = row[1]
        dbUser = row[0]
        dbPass = row[2]
        print(id,dbUser,dbPass)
        if creaDigest(username)==dbUser:
            correct = True if creaDigest(password) == dbPass else False
            if correct:break
    return correct,id

#salva sul db lo storico di ció che si fa con cookie
def salvaDB(stato):
    con = sqlite3.connect('./dati.db')
    cur = con.cursor()
    id = request.cookies.get("id")#
    #faccio la insert dei valori
    cur.execute(f"INSERT INTO storico VALUES ('{id}','{stato}','{datetime.today()}')")
    #salvo le modifiche
    con.commit()
    #chiudo il db
    con.close()

#pagina di login
@app.route('/', methods=['GET', 'POST'])
def login():
    error = None
    if request.method == 'POST':
        #prendo i campi username e password
        username = request.form['username']
        password = request.form['password']
        #controllo se sono giuste
        completion,id = validate(username, password)
        if completion ==False:
            #messaggio di errore
            error = 'Invalid Credentials. Please try again.'
            resp = make_response(render_template('login.html', error=error))
        else:
            #accedo alla pagina index
            resp = make_response(redirect(url_for('index')))
            #setto i cookie
            resp.set_cookie("id",str(id))
        return resp
    #restituisco la pagina di login
    return make_response(render_template('login.html'))
#pagina di index
@app.route('/index', methods=['GET', 'POST'])
def index():
    #controllo se c'é una richiesta di POST
    if request.method == 'POST':
        #controllo il bottone Invia
        if request.form.get('Invia') == 'Invia':
            #prendo i campi
            stato = request.form['stato']
            v = request.form['verde']
            g = request.form['giallo']
            r = request.form['rosso']
            #controllo lo stato del semaforo
            if stato == "ACCESO":
                #invio le variabili al test
                return redirect(url_for('test',stato=stato,v=v,g=g,r=r))
            elif stato == "SPENTO":
                #invio solo lo stato perché il semaforo é spento
                return redirect(url_for('test', stato=stato))
            else:
                error = 'Invalid state'
                return render_template('index.html', error=error)
            
    return render_template('index.html')

#pagina di test
@app.route('/test', methods=['GET', 'POST'])
def test():
    #prendo le variabili come arogmenti
    stato = request.args.get('stato')
    v = request.args.get('v')
    g = request.args.get('g')
    r = request.args.get('r')
    #salvo sul db le modifiche
    salvaDB(stato)
    #contrllo che abbia inserito i parametri per fare il test
    if stato == "" or v==""or g==""or r=="":
        resp = render_template('test.html',esegui="Non hai inserito dei parametri")
    #controllo se il semaforo é acceso
    elif stato == "ACCESO":
        #passo i parametri
        if v!="":Semaforo.verde(int(v))
        if g!="":Semaforo.giallo(int(g))
        if r!="":Semaforo.rosso(int(r))
        resp = render_template('test.html',esegui="Test eseguito")
    #se il semaforo é spento inizio il ciclo
    else:
        for _ in range(3):
            Semaforo.giallo(1)
            Semaforo.luci_spente(1)
        resp = render_template('test.html',esegui="Test eseguito")
    return resp 

if __name__=="__main__":
    app.run(debug=True, host='127.0.0.1')