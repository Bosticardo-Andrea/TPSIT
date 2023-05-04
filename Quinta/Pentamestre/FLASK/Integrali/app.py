from flask import Flask, render_template, request,redirect, url_for,make_response
from datetime import datetime
import hashlib,sqlite3
from sympy import *
app = Flask(__name__)
def creaDigest(stringa:str)->str:
    hasher = hashlib.sha256()
    hasher.update(stringa.encode())
    hash_stringa = hasher.hexdigest()
    return hash_stringa

def validate(username, password):
    global resp
    correct = False
    con = sqlite3.connect('./accessi.db')
    cur = con.cursor()
    cur.execute("SELECT * FROM utenti")
    rows = cur.fetchall()
    con.close()
    for row in rows:
        id = row[0]
        dbUser = row[1]
        dbPass = row[2]
        if creaDigest(username)==dbUser:
            correct = True if creaDigest(password) == dbPass else False
            if correct:break
    return correct,id

def risolvi_integrale(f,a=None,b=None,x=symbols('x')):
    if a == None or b == None:return integrate(f,x)
    else:return integrate(f, (x, a, b))

def salvaDB(f,ris,a="",b=""):
    con = sqlite3.connect('./accessi.db')
    cur = con.cursor()
    id = request.cookies.get("id")
    stringa = f"INSERT INTO storico VALUES ({int(id)},{f},{a},{b},{ris},{datetime.today()})"
    print(stringa)
    cur.execute(f"INSERT INTO storico VALUES ('{id}','{f}','{a}','{b}','{ris}','{datetime.today()}')")
    con.commit()
    con.close()
    

@app.route('/', methods=['GET', 'POST'])
def login():
    error = None
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        completion,id = validate(username, password)
        if completion ==False:
            error = 'Invalid Credentials. Please try again.'
            resp = make_response(render_template('login.html', error=error))
        else:
            resp = make_response(redirect(url_for('index')))
            resp.set_cookie("id",str(id))
        return resp
    return make_response(render_template('login.html'))

@app.route('/index', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        if request.form.get('Calcola') == 'Calcola':
            f = request.form['f']
            a = request.form['a']
            b = request.form['b']
            if a == "" or b == "None" :ris = risolvi_integrale(f)
            elif b<a: return render_template('index.html', formula=f,ris="errore: b < a")
            else:ris = risolvi_integrale(f,a,b)
            f = Integral(f, symbols('x'))
            salvaDB(f,a,b,ris)
            return render_template('index.html', formula=latex(f),ris=latex(ris))
    return render_template('index.html')

def main():
    pass

if __name__=="__main__":
    app.run(debug=True, host='127.0.0.1')
    main()