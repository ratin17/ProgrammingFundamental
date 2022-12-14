from time import sleep

def leave():
    print("\nExiting ..",end="")
    sleep(1)
    print(" .. ",end="")
    sleep(1)
    print(" .. ")
    sleep(1)
    print("Logged Out !")


def digBook(wrtitting):
    bookFile="G:\ProgrammingFundamentals\OOP_with_Python\Exams\Exam_4_TheoryMid\ebook.txt"

    f = open (bookFile, 'w')
    f.write(wrtitting)
    f.close()

    f = open (bookFile, 'r')
    contents=f.read()
    
    pages=contents.split('--')
    n=len(pages)

    i=0
    while i<n:
        print("\n|'''''''''''''''''''''''''''''''''''''''|\n")
        print(pages[i])
        print("\n|_______________________________________|\n")

        if i==n-1:
            print("\nWOW ! You have finished reading the book !")
            leave()
            break

        choice=input("[enter - read more, press q to quit]")

        try:
            jump=int(choice)

            if jump<0:
                i=max(i+jump,0)
                continue
            else:
                i=min(i+jump+1,n-1)
                continue

        except ValueError:
            if choice=="":
                i=i+1
                continue
            elif choice=='q':
                leave()
                break
            else:
                print("\nInvalid Choice !")
                leave()
                break
                
        
    f.close()




p=""
for i in range(20):
    p=p+f'This is the page number : {i+1}--'
p=p+f'This is the last page'

digBook(p)