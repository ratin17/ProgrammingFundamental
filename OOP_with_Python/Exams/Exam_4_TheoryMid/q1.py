
def checkPalindrome(inStr):
    i,j=0,len(inStr)-1
    while(i<=j):
        if inStr[i]!=inStr[j]:
            print(f'"{inStr}" is not Palindrome')
            return
        i+=1
        j-=1

    print(f'"{inStr}" is Palindrome')


# checkPalindrome("abc")

# checkPalindrome("a")

checkPalindrome("abba")

