from flask import Flask, render_template, request,redirect, url_for,make_response,jsonify
import sqlite3,turtle,os
from datetime import datetime

app = Flask(__name__)
t = turtle.Turtle()
sfondo = turtle.Screen()

def salvaDB(id,idmov):
    con = sqlite3.connect('./turtle.db')
    cur = con.cursor()
    cur.execute(f"INSERT INTO cronologia VALUES (NULL,'{id}','{idmov}','{datetime.today()}')")
    con.commit()
    con.close()
    
@app.route('/cron', methods=['GET'])
def inviaCron():
    if "id" in request.args:
        id = int(request.args['id'])
        con = sqlite3.connect('./turtle.db')
        cur = con.cursor()
        cur.execute(f"SELECT * FROM CLIENT_AMMESSI WHERE id = {id}")
        row = cur.fetchone()
        con.close()
        if not row:return"client non ammesso"
        else:
            con = sqlite3.connect('./turtle.db')
            cur = con.cursor()
            cur.execute(f"SELECT * FROM cronologia WHERE idClient = {id}")
            rows = cur.fetchall()
            con.close()
            print(rows,id)
            return jsonify(rows)       
    else:return "Error: No id field provided, Please specify an id."

def muovi(id,mov):
    con = sqlite3.connect('./turtle.db')
    cur = con.cursor()
    cur.execute(f"SELECT id,nome FROM Movimenti WHERE nome = '{mov}'")
    row = cur.fetchone()
    con.close()
    os.system("clear")
    if mov == "avanti":t.forward(100)
    elif mov == "sx":t.right(90)
    if mov == "dx":t.left(90)
    salvaDB(id,row[0])

@app.route('/mov', methods=['GET'])
def movimenti():
    while 1:
        if "id" in request.args:
            id = int(request.args['id'])
            con = sqlite3.connect('./turtle.db')
            cur = con.cursor()
            cur.execute(f"SELECT * FROM CLIENT_AMMESSI WHERE id = {id}")
            row = cur.fetchone()
            con.close()
            if not row:return"client non ammesso"
            else:
                movimento = request.args['mov']
                muovi(id,movimento)
                return "Tutto ok"
        else:return "Error: No id field provided, Please specify an id."

if __name__=="__main__":
    app.run(debug=True, host='127.0.0.1')