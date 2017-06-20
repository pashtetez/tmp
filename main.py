from flask import Flask , request
from flask_cors import CORS, cross_origin
import json
from  lcd import LCD

lcd = LCD()
lcd.LCDinit()

app = Flask(__name__)
CORS(app, supports_credentials=True)

@app.route("/data", methods=['GET', 'POST', 'OPTIONS'])
def script():
    global lcd 
    d = json.loads(request.get_data())
    for x in d:
        if x['pin']=='RW':
            lcd.setRW(x['val'])
        if x['pin']=='A0':
            lcd.setA0(x['val'])
        if x['pin']=='E1':
            lcd.setE1(x['val'])
        if x['pin']=='E2':
            lcd.setE2(x['val'])
        if x['pin']=='E':
            lcd.setE(x['val'])
        if x['pin']=='RES':
            lcd.setRES(x['val'])
        if x['pin']=='D':
            lcd.setD(x['val'])
    print d;
    return "" 

@app.route("/getDisplay", methods=['GET', 'POST', 'OPTIONS'])
def getDisplay():
    global lcd
    a=[]
    for x in range(128):
        a.append([])
        for y in range(64):
            a[x].append(lcd.getPixel(x,y))
    return json.dumps(a)

if __name__ == "__main__":
    
    app.run(host='0.0.0.0')
