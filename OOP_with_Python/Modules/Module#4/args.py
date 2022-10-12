
def add(num1,num2=0,*numbers,num4):
    result=0
    print(num1)
    print(num2)
    print(numbers)

    result+=num1+num2
    for number in numbers:
        result+=number
    result+=num4

    return result


print(add(1,2,3,10,10,10))