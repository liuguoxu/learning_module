# flask test
from flask import Flask
from flask import request
from flask import jsonify 

app = Flask(__name__)

@app.route('/')
def main_page():
    return 'main page~~'

if __name__ == '__main__':
    app.run(port = 8080)
