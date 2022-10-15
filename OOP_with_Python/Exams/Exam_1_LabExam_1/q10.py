

a = ['oh', 'Emelia', 'to']

def create_new_string(s,a):

    myPage=open("out.txt", "w")
    myPage.write("")
    myPage.close()

    cleanS=""
    for i in s:
        if(((ord(i)>64)and(ord(i)<91))or((ord(i)>96)and(ord(i)<123)or(i==" "))):
            cleanS+=i
    
    b=list()
    for word in a:
        b.append(word.lower())

    sWords=cleanS.split(" ")

    output=list()

    myPage=open("out.txt", "a")
    for word in sWords:
        if word.lower() in b:
            if word not in output:
                if word=="to":
                    output.append(word)
                    skip=sWords.index(word)
                    myPage.write(sWords[sWords.index(word,skip+1)+1])
                    myPage.write(" ")
                else:
                    output.append(word)
                    myPage.write(sWords[sWords.index(word)+1])
                    myPage.write(" ")
    myPage.close()


s = "Oh, I got two tickets for Dhaka. I and Emelia love to visit different places very much. This time we are going to Bangladesh."

create_new_string(s,a)
