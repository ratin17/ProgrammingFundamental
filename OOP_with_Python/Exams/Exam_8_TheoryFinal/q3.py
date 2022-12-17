
from math import pi

message = 'Hello'

def greet():

    # local variable
    Person = 'Ratin'
    
    print("\tGlobal 'message' is accessd inside greet()\n")
    print(f'{message} , {Person}\n')

    print(f'You are welcome by PI={pi}\n')
    print("\n\tBuilt in 'pi' is also accessd inside greet()\n")


greet()

# try to access 'Person' variable 
# outside greet() function


