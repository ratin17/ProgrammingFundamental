
n=int(input("Enter an integer:"))

i=1
while i<n+1:
    j=1
    while j<n+1:
        if(i==j):
            print("1",end="")
        elif j<i:
            print(j+1,end="")
        else:
            print(j,end="")
        j=j+1
    print("\n",end="")
    i=i+1
