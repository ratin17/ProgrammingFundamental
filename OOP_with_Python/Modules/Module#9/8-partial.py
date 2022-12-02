from functools import partial

def dToN(a,b,c,d):
    return a*1000+b*100+c*10+d

n1=dToN(2,1,0,8)

print(n1)

fourth_only=partial(dToN,b=0,c=0,d=0)

n2=fourth_only(6)

print(n2)