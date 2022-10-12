#global name : balance
balance=500

def credit(amount):
    global balance
    print("Current balance : ",balance)
    balance = balance-amount
    return balance


print("After credit, balance : ",credit(20))