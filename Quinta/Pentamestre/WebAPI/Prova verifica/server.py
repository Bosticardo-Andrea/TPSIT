from flask import Flask, render_template, request, redirect, url_for, make_response, jsonify
import sqlite3

app = Flask(__name__)

def creaConn():
    """
    Crea una connessione al database e restituisce la connessione e il cursore.

    :return: la connessione e il cursore
    :rtype: tuple
    """
    con = sqlite3.connect('./db.db')
    cur = con.cursor()
    return con,cur

def salvaDB(idU, ris, idO):
    """
    Salva i risultati di un'operazione nel database.

    :param idU: l'id dell'utente che ha eseguito l'operazione
    :type idU: int
    :param ris: il risultato dell'operazione
    :type ris: str
    :param idO: l'id dell'operazione
    :type idO: int
    """
    con,cur= creaConn()
    cur.execute(f"INSERT INTO risultati VALUES ('{idU}', '{ris}', '{idO}')")
    con.commit()
    con.close()
    
def controlloUtenti(idU):
    """
    Controlla se un utente è presente nel database.

    :param idU: l'id dell'utente da controllare
    :type idU: int
    :return: True se l'utente non è presente nel database, False altrimenti
    :rtype: bool
    """
    con,cur= creaConn()
    cur.execute(f"SELECT * FROM utenti WHERE id = {idU}")
    row = cur.fetchone()
    con.close()
    return row is None

@app.route('/ammessi', methods=['GET'])
def ammessi():
    con,cur = creaConn()
    cur.execute(f"SELECT * FROM utenti")
    rows = cur.fetchall()
    con.close()
    return jsonify(rows)

@app.route('/SalvaOperazioni', methods=['GET'])
def SalvaOperazioni():
    """
    Salva un'operazione nel database.

    :return: una stringa che indica se l'operazione è stata salvata con successo o se il client non è ammesso
    :rtype: str
    """
    if "idU" in request.args and "ris" in request.args and "idO" in request.args:
        idU = int(request.args['idU'])
        if controlloUtenti(idU):
            return "Client non ammesso"
        print(idU, request.args['ris'], request.args['idO'])
        salvaDB(idU, request.args['ris'], int(request.args['idO']))
        return "Operazione salvata con successo"
    else:
        return "Error: No id field provided, Please specify an id."

@app.route('/operazioni', methods=['GET'])
def operazioni():
    """
    Restituisce le operazioni eseguite da un utente.

    :return: una lista di tuple con i dati delle operazioni
    :rtype: list
    """
    if "idU" in request.args:
        idU = int(request.args['idU'])
        if controlloUtenti(idU):
            return "Client non ammesso"
        else:
            con,cur= creaConn()
            cur.execute(f"SELECT * FROM operazioni WHERE client = {idU}")
            rows = cur.fetchall()
            con.close()
            return jsonify([row[:-1] for row in rows])
    else:
        return "Error: No id field provided, Please specify an id."

if __name__ == "__main__":
    app.run(debug=True, host='127.0.0.1')
