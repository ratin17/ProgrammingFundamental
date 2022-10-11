data="azg"
shift=58
eData=''

for char in data:
    eData+= chr(((ord(char)+shift-97)%26)+97)

print(eData)
