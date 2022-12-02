
n=list(range(20))

sortedN=sorted(n,key=lambda a:a)

student=[
    {'name':'ratin','roll':26},
    {'name':'n','roll':261},
    {'name':'rtin','roll':265},
    {'name':'rn','roll':26}
]

sortedS=list(sorted(student,key=lambda Student:Student['roll']))

print(sortedS)