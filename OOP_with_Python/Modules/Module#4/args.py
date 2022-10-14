
def add(num1,num2=0,*numbers):
    result=num1

    result+=num2
    for number in numbers:
        result+=number

    return result

def mul(num1,num2=1,*numbers):
    result=num1

    result*=num2
    for number in numbers:
        result*=number

    return result



def marks(course,student,*marks,**marksInfo):
    print("Course Name :",course)
    print("Student Name :",student)
    total=0
    exam=0
    for mark in marks:
        total+=mark
    print("Total Marks :",total)
    for info,value in marksInfo.items():
        print(info,":",value)
        if info=="Exams":
            exam=value

    print("Average Marks :",total/exam)



marks("OOP","Ratin",89,99,65,32,Exams=4,Teacher="Jhankar Mahbub",Modules=34)

print(add(1,2,3,10,10,10))

print(mul(1,4,7))
