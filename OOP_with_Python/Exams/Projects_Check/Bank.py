#User start
class User:
    def __init__(self,username,email,password) -> None:
        self.username = username
        self.email = email
        self.password = password
        self._balance = 0
        self.transactions = []

    def deposit(self,amount):
        if amount>0:
            self._balance+=amount
            Bank._total_available_balance+=amount
            self.transactions.append(f'Deposit: {amount} taka')
            print(f'{amount} taka deposited successfully')
    
    def withdraw(self,amount):
        if Bank._total_available_balance < amount:
            print('the bank is bankrupt')
        elif amount>self._balance:
            print('Insufficient Balance')
        elif amount<=0:
            print('Please provide correct amount')
        else:
            self._balance-=amount
            Bank._total_available_balance-=amount
            self.transactions.append(f'Withdraw: {amount} taka')
            print(f'{amount} taka has withdrawn successfully')

    def check_balance(self):
        print(f'Your current balance is {self._balance}')
    
    

    def take_loan(self,amount):
        if Bank.loan_active:
            if amount <= 2*self._balance and amount<=Bank._total_available_balance:
                self._balance+=amount
                Bank._total_available_balance-= amount
                Bank._total_loan_amount+=amount
                self.transactions.append(f'Loan: {amount} taka')
                print(f'{amount} taka loan has been sanctioned')
            else:
                print(f'{amount} taka loan cannot be granted because of insufficient amount')
        else:
            print(f'Sorry Loan feature is off right now')

    def money_transfer(self,username,amount):
        for w in Bank.user_list:
            # if username != w['username']:
            #     print('Account doesnot exists')
            if amount<=self._balance:
                self._balance-=amount
                self.transactions.append(f'Transfer to {username}: {amount} taka')
                print(f'Transfer to {username}: {amount} taka successfully')
                


    def check_transaction(self):
        for t in self.transactions:
            print(t)
#User end

#bank start
class Bank:
    _total_available_balance = 0
    _total_loan_amount = 0
    user_list = []
    loan_active = True
    def __init__(self,name) -> None:
        self.name = name
    
    def create_account(self):
        username = input('Username: ')
        email = input('Email: ')
        password = input('Password: ')

        self.new_user = User(username,email,password)
        self.user_list.append(vars(self.new_user))
        print('\nAccount created successfylly\nPlease Login Now!')
    
    def get_users(self):
        return self.user_list

    @classmethod
    def _check_total_balance(self):
        print(f'Total balance: {self._total_available_balance}')
    
    @classmethod
    def _check_loan_amount(self):
        print(f'Total loan: {self._total_loan_amount}')
        
    
    @classmethod
    def loan_feature(self,active):
        if active == 'on':
            self.loan_active = True
            print('Loan feature is active')
        elif active == 'off':
            self.loan_active = False
            print('Loan feature is deactive')

#bank end



    
            
        
       


    