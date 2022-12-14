
def angrams(words):
    n=len(words)
    angm=[]

    track=[]
    for i in range(n):
        track.append(False)
    
    for i in range(n):
        a=[]

        if(track[i]==False):
            a.append(words[i])
            d={}
            keyss=[]
            for p in words[i]:
                if p in keyss:
                    d[p]=d[p]+1
                else:
                    d[p]=1
                    keyss.append(p)
            

            for j in range(i+1,n):
                if(track[j]==False and len(words[i])==len(words[j])):
                    dc={}
                    keysss=[]
                    for q in words[j]:
                        if q in keysss:
                            dc[q]=dc[q]+1
                        else:
                            dc[q]=1
                            keysss.append(q)
                    
                    if(d==dc):
                        # print(words[j],d,dc)
                        a.append(words[j])
                        track[j]=True

        if len(a)>0:
            angm.append(a)

    return angm


print(angrams(['lame','folder','male','eat','ate', 'done', 'tea', 'soup', 'node','colder','yyy','yyy']))
