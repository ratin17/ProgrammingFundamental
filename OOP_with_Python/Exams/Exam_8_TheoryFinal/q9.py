
import threading

def f1():
    for i in range(5):
        print(f"f1 - {i}\n")
 
def f2():
    for i in range(5):
        print(f"f2 - {i}\n")
 
def f3():
    for i in range(5):
        print(f"f3 - {i}\n")
       
def f4():
    for i in range(5):
        print(f"f4 - {i}\n")


thread1=threading.Thread(target=f1,args=())
thread1.start()

thread2=threading.Thread(target=f2,args=())
thread2.start()

thread3=threading.Thread(target=f3,args=())
thread3.start()

thread4=threading.Thread(target=f4,args=())
thread4.start()

