def digBook(wrtitting):
    bookFile="G:\ProgrammingFundamentals\OOP_with_Python\Exams\Exam_4_TheoryMid\ebook.txt"

    f = open (bookFile, 'w')
    f.write(wrtitting)
    f.close()

    f = open (bookFile, 'r')
    contents=f.read()
    
    pages=contents.split('--')
    
    for i in range(len(pages)):
        print(pages[i])

        choice=input("[enter - read more, press q to quit]")
        
        if choice=='\r':
            continue
        elif choice=='q':
            break

    f.close()


digBook("This is first page content--Now we are in the second page--This is Next page--This is Next page--This is Next page--This is Next page")