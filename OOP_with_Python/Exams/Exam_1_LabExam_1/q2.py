
from pyautogui import sleep
import requests
import json

def weather_data(longitude,lattitude):
    url = "https://weatherbit-v1-mashape.p.rapidapi.com/current"

    querystring = {"lon":longitude,"lat":lattitude}

    headers = {
        "X-RapidAPI-Key": "971cedfe8cmshb1a4469d57a25bep12bf59jsn520142d7d187",
        "X-RapidAPI-Host": "weatherbit-v1-mashape.p.rapidapi.com"
    }

    response = requests.request("GET", url, headers=headers, params=querystring)


    content=response.text
    info=json.loads(content)
    stat=info["data"]

    weather={}
    weather["Location"]=stat[0]["city_name"]
    weather["dateTime"]=stat[0]["datetime"]
    weather["temp"]=stat[0]["temp"]
    weather["wd"]=stat[0]["wind_cdir_full"]
    weather["ws"]=stat[0]["wind_spd"]
    weather["summary"]=stat[0]["weather"]["description"]


    print("---------------------------------")
    print("Location:",weather["Location"])
    print("---------------------------------")
    print("Date & Time:",weather["dateTime"])
    print("---------------------------------")
    print("Temeperature:",weather["temp"],"Degree Celcius")
    print("---------------------------------")
    print("Wind Direction:",weather["wd"])
    print("---------------------------------")
    print("Wind Speed:",weather["ws"])
    print("---------------------------------")
    print("Weather Summary:",weather["summary"])
    print("---------------------------------")


longitude="90.399452"
lattitude="23.777176"

while True:
    weather_data(longitude,lattitude)
    sleep(30*60)





