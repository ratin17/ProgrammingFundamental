
uid=0

class Student:
    id=0

    def __init__(self,name,mark):
        self.name=name
        self.mark=mark


    def setUid(self):
        global uid
        uid=uid+1
        self.id=uid
        


    def writeFile(self):
        f = open("output.txt", "a")
        f.write(f"\nStudent id: {self.id} , Student Name: {self.name}, Mark : {self.mark}\n\n")
        
        f.close()


def inputStudent():
    n=int(input("How many students you want to input:"))
    for i in range(n):
        name = input("Student name: ")
        mark = input("Mark :" )
        s = Student(name, mark)
        s.setUid()
        s.writeFile()


inputStudent()
