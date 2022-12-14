


def centreAlign(width=60):


    inputFile="G:\ProgrammingFundamentals\OOP_with_Python\Exams\Exam_4_TheoryMid\input.txt"

    outputFile="G:\ProgrammingFundamentals\OOP_with_Python\Exams\Exam_4_TheoryMid\output.txt"

    f = open(inputFile, "r")
    
    lines=f.readlines()
    f.close()

    #Clearing the output file
    f = open (outputFile, 'w')
    f.write("")
    f.close()

    
    f = open (outputFile, 'a')
    
    for line in lines:
        print(line.center(width))
        f.write(line.center(width))
    
    f.close()


centreAlign()
