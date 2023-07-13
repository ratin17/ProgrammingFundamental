from Bank import User,Bank
def main():
    while True:
        bank = Bank('Shonali')
        print('1. Create an account\n2. Login to your account\n3. Exit')
        user_input = int(input('Enter Choice: '))
        if user_input==3:
            break
        elif user_input==1:
            bank.create_account()
        elif user_input == 2:
            username = input('Enter Username: ')
            email = input('Enter Email: ')
            password = input('Enter Password: ')
            userer = User(username,email,password)
            flag = 0
            isAdmin = False

            if email=='admin@gmail.com':
                isAdmin=True
            if not isAdmin:
                for user in bank.get_users():
                    if user['username']==username and user['email']==email and user['password']==password:
                        flag = 1
                        break
                if flag:
                    while True:
                        print(f'Welcome {username} to our bank')
                        print(f'1. Deposite money\n2. Withdraw money\n3. Check balance\n4. Transfer money\n5. Check transaction history\n6. Take loan\n7.Exit')

                        press = int(input('Enter Choice: '))
                        if press == 7:
                            break
                        elif press == 1:
                            amount = int(input('Enter amount: '))
                            userer.deposit(amount)
                        elif press==2:
                            amount = int(input('Enter amount: '))
                            userer.withdraw(amount)
                        elif press==3:
                            userer.check_balance()
                        elif press==4:
                            recipant = input('Enter username: ')
                            amount = int(input('Enter amount: '))
                            userer.money_transfer(recipant,amount)
                        elif press==5:
                            userer.check_transaction()
                        elif press==6:
                            amount = int(input('Enter amount: '))
                            userer.take_loan(amount)

                else:
                    print('No username found')
            else: 
                while True:
                    print(f'Welcome {username}')
                    print('1. Bank\'s total balance\n2. Total loan amount\n3. On/Off loan feature\n4. Exit')
                    press = int(input('Enter Choice: '))
                    if press == 4:
                        break
                    elif press==1:
                        bank._check_total_balance()
                    elif press==2:
                        bank._check_loan_amount()
                    elif press==3:
                        active=input('Plese write on/off: ')
                        bank.loan_feature(active)




if __name__ == '__main__':
    main()