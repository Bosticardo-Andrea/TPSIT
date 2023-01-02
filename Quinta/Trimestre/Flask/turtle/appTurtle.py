from flask import Flask, render_template, request
app = Flask(__name__)
@app.route("/", methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        if request.form.get('su') == 'su':
            print("su")
        elif  request.form.get('giu') == 'giu':
            print("giu")
        elif  request.form.get('dx') == 'dx':
            print("dx")
        elif  request.form.get('sx') == 'sx':
            print("sx")
        else:
            print("Unknown")
    elif request.method == 'GET':
        return render_template('index.html')
    
    return render_template("index.html")

if __name__ == '__main__':
    app.run(debug=True, host='localhost')