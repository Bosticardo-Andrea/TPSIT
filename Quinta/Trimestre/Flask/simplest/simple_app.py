from flask import Flask

app = Flask(__name__) #crea una variabile di nome app

@app.route('/')
def index():
    return 'Ciao!'
#@app --> decoratore, unisce un URL ad una funzione
@app.route('/pagina/')
def index2():
    return 'pagina!'

if __name__ == '__main__':
    #runna l'app debug=posso modifacre a caldo
    #host = ip della bind
    #port = 5000
    app.run(debug=True, host='localhost')
    