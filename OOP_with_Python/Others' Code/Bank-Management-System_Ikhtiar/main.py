from User import Bank
from Admin import Admin

def main():
    bank = Bank()
    admin = Admin(bank)
    admin.create_account('Ikhtiar Uddin', 1000) #balance set kore disi
    admin.create_account('Kutub Uddin', 1000) #balance set kore disi
 
    total_balance = admin.get_total_balance()
    print('Total Bank Balance:', total_balance)
 
    Ikhtiar = bank.accounts[0]
    Ikhtiar.deposit(500)
    if not bank.is_bankrupt():
        Ikhtiar.withdraw(140)
    else:
        print("The bank is bankrupt.")
    history = Ikhtiar.get_transaction_history()
    print("Ikhtiar Transaction History:")
    for transaction in history:
        print(transaction)

    balance = Ikhtiar.get_balance()
    print("After deposit and withdraw balance :",balance)

    Kutub = bank.accounts[1]
    Kutub.deposit(400)

    if not bank.is_bankrupt():
        Kutub.withdraw(700)
    else:
        print("The bank is bankrupt.")

    Kutub = bank.accounts[1]
    Ikhtiar.transfer(10, Kutub)

    Ikhtiar = bank.accounts[0]
    Kutub.transfer(50, Ikhtiar)

    history = Kutub.get_transaction_history()
    print("Kutub Transaction History:")
    for transaction in history:
        print(transaction)

    balance = Kutub.get_balance()
    print("After deposit and withdraw balance :",balance)

    balance = Ikhtiar.get_balance()
    print('Now Exactly Amount of Ikhtiars: ',balance)
    balance = Kutub.get_balance()
    print('Now Exactly Amount of Kutubs: ',balance)


    

    if bank.loan_feature_enabled:
        loan_amount = Ikhtiar.get_balance() * 2
        bank.total_loan_amount += loan_amount
        Ikhtiar.deposit(loan_amount)
        print("Loan Granted for Ikhtiar:", loan_amount)
    else:
        print("Loan feature is currently disabled.")

    if bank.loan_feature_enabled:
        loan_amount = Kutub.get_balance() * 2
        bank.total_loan_amount += loan_amount
        Kutub.deposit(loan_amount)
        print("Loan Granted for Kutub:", loan_amount)
    else:
        print("Loan feature is currently disabled.")

    admin.create_account("Admin")
    admin.enable_loan_feature()
 
    loan_feature_status = bank.loan_feature_enabled
    print("Loan Feature Status:", loan_feature_status)
    

    total_loan_amount = admin.get_total_loan_amount()
    print("Total Loan Amount:", total_loan_amount)


# main 
if __name__ == "__main__":
    main()
