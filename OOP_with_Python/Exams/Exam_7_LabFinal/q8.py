
def Rsum_odd(n,total):
    if n==1:return total
    elif n%2==0:return Rsum_odd(n-1,total)
    else: return Rsum_odd(n-2,total+n)

# print(Rsum_odd(6,0))


def sum_odd(n,total):
    for i in range(3,n+1):
        if i%2!=0:total+=i
    return total


# print(sum_odd(6,0))

def Rmax(l,n):
    if l==[]:return n
    elif l[0]>n: return Rmax(l[1:],l[0])
    else : return Rmax(l[1:],n)

# print(Rmax([1,255,3,4,544],56))

def max(l,n):
    ans=n
    for i in l:
        if i>ans:ans=i
    return ans


print(max([1,255,3,4,544],56))

def mylen(l,n):
    for i in l:
        n+=1
    return n


print(mylen([1,3],0))