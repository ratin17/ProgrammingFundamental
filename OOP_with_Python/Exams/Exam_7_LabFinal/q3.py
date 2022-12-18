
    
def halfAdder(A,B):
    
    # ^ is bitwise XOR operator
    sum= A ^ B

    # & is bitwise AND operator
    carry=A & B

    return (sum,carry)


def Test(inp,exOut):

    testPassed=True

    print("\nTesting .. .. .. ..")
    print("\n_______________________________________________________")
    print(f'Input\t\t Expected_Output\t\t Output')
    print("_______________________________________________________")

    for row in range(len(inp)):
        A=inp[row][0]
        B=inp[row][1]

        X=exOut[row][0]
        Y=exOut[row][1]

        S=halfAdder(A,B)[0]
        C=halfAdder(A,B)[1]

        if S!=X or C!=Y:
            testPassed=False

        print(f'{A}\t{B}\t\t{X}\t{Y}\t\t{S}\t{C}')

    print("_______________________________________________________")

    print("\nTest Passed !\n") if testPassed else print("\nTest didn't Passed !\n")



myInput=[
    [0,0],
    [0,1],
    [1,0],
    [1,1]
]

expectedOutput=[
    [0,0],
    [1,0],
    [1,0],
    [0,1]
]


Test(myInput,expectedOutput)
