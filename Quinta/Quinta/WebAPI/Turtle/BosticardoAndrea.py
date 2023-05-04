from flask import Flask, render_template, request,redirect, url_for,make_response,jsonify
import sqlite3
import turtle
from datetime import datetime
from threading import Thread
th = {}
class MyThread(Thread):
    def __init__(self):
        Thread.__init__(self)
        self.running = True
        self.t = turtle.Turtle()
    def run(self):
        while self.running:pass
    def up(self):self.t.forward(100)
    def dx(self):self.t.right(90)
    def sx(self):self.t.left(90)
    def stop(self):
        self.running = False
        turtle.bye()  # chiude la finestra turtle

app = Flask(__name__)

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
    print()
    if id not in th.keys():
        th[id] = MyThread()
        th[id].start()
    if mov == "avanti":th[id].up()
    elif mov == "sx":th[id].dx()
    if mov == "dx":th[id].sx()
    salvaDB(id,row[0])

@app.route('/mov', methods=['GET'])
def movimenti():
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