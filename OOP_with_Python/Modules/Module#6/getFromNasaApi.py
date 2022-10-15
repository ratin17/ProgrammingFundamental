import requests
import json
import PyWallpaper

api_url="https://api.nasa.gov/planetary/apod?api_key=J4k747jYwPXDs7yyhsxKQYKVTK77OBlMTuDsFD3Y"

response=requests.get(api_url)
content=response.content.decode('UTF-8')

#from json string to dictionary
dict_content=json.loads(content)

image_url=dict_content['url']

image_response=requests.get(image_url)
image_content=image_response.content

with open("apod.png","wb") as image:
    image.write(image_content)

PyWallpaper.change_wallpaper("G:\ProgrammingFundamentals\apod.png")


