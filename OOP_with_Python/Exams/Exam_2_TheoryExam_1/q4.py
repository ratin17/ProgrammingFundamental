
x=input("Enter input in format - 'x3b4U5i2' :")

char=""
times=""
result=""
end=False

i=0
while(i<len(x)):
    char=x[i]

    i=i+1
    while(ord(x[i])>=48 and ord(x[i])<=57):
        times=times+x[i]

        if i+1<len(x):
            i=i+1
        else:
            end=True
            break
    
    for j in range(int(times)):
        result=result+char
    
    times=""

    if end==True:
        break


result="".join(sorted(result.lower()))



print("Output: ",result)
