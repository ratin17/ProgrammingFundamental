def clean_string(text):
    clean=""
    for i in text:
        if(((ord(i)>64)and(ord(i)<91))or((ord(i)>96)and(ord(i)<123))):
            clean+=i
    return clean

s = "P::::::,,,,,h;;;;i,,,t--r;,:o..N"
output = clean_string(s)
print(output)