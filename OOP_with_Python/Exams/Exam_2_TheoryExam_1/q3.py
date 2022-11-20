
s=input('Enter String:')

temp=""
reversed=""

for i in range(len(s)):
    if(s[i]==' '):
        temp = temp[::-1]
        reversed=reversed+temp+" "
        temp=""
    else:
        temp=temp+s[i]

temp = temp[::-1]
reversed=reversed+temp

print(reversed)