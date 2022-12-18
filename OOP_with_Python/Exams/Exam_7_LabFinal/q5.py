

week=["Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday",]
rainfall=[]
totalrain=0

for day in week:
    print(f"Enter {day}'s ",end="")
    temp=float(input("Rainfall:"))
    rainfall.append(temp)
    totalrain+=temp

max,min=0,99999999
maxdays=[]
mindays=[]

for i in range(len(rainfall)):
    if rainfall[i]<min:
        min=rainfall[i]

    if rainfall[i]>max:
        max=rainfall[i]

for rain in range(len(rainfall)):
    if rainfall[rain]==min:
        mindays.append(week[rain])
    if rainfall[rain]==max:
        maxdays.append(week[rain])

print(f"\nMinimum Rainfall of  [{min}] on ",end="")
for day in mindays:
    print(f"{day}  ",end="")

print(f"\n\nMaximum Rainfall of  [{max}] on ",end="")
for day in maxdays:
    print(f"{day}  ",end="")

print("\n\n")

# part of question 5

mean=totalrain/7
rainSquares=list((x-mean)*(x-mean) for x in rainfall)
sumOfSquares=0
for rain in rainSquares:
    sumOfSquares+=rain

sumOfSquaresByItems=sumOfSquares/7

standardDeviation=sumOfSquaresByItems**0.5

print(f"Mean : {mean}\n")
print(f"Standard Deviation : {standardDeviation}\n")



