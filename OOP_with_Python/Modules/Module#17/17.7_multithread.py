
import threading

def funA(n):
    for i in range(n):
        print(f'From A : {i}')

def funB(n):
    for i in range(n):
        print(f'From B : {i}')


# funB(100)
# funA(100)

threadA=threading.Thread(target=funA,args=(100,))

threadA.start()

threadB=threading.Thread(target=funB,args=(100,))
threadB.start()