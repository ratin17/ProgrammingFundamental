

def nearly_equal(a,b):
    mismatch=0
    i=j=0
    c=""
    
    if abs(len(a)-len(b))>1:
        print("Strins are not Nearly-Equal")
        return False

    while(i<len(a) and j<len(b)):
        if(a[i]!=b[j]):
            mismatch+=1
            if(len(a)>len(b)):
                j-=1
            elif(len(a)==len(b)):
                if c=="":
                    c=b[j]
                else:
                    if c==a[i]:
                        mismatch-=1
            else:
                i-=1
        if(mismatch>1):
            print("Strins are not Nearly-Equal")
            return False
        i+=1
        j+=1
    
    if(mismatch<2):
            print("Strins are Nearly-Equal")
            return True



print(nearly_equal('pearl', 'pearzl'))