d={'id':87,'name':"Ratin Haq", 'male':True}

dItems=d.items()

print(type(dItems))
print(dItems)

for i in d:
    print(type(i),' ',i)

for i,j in d.items():
    print(i,j)