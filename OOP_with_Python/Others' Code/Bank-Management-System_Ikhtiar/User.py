class Bank:
    def __init__(self):
        self.accounts = []
        self.total_balance = 0
        self.total_loan_amount = 0
        self.loan_feature_enabled = True

    def create_account(self, name, initial_balance=0):
        account = Account(name, initial_balance)
        self.accounts.append(account)
        self.total_balance += initial_balance

    def get_total_balance(self):
        return self.total_balance

    def get_total_loan_amount(self):
        return self.total_loan_amount

    def enable_loan_feature(self):
        self.loan_feature_enabled = True

    def disable_loan_feature(self):
        self.loan_feature_enabled = False

    def is_bankrupt(self):
        self.total_balance < 0

class Account:
    def __init__(self, name, balance=0):
        self.name = name
        self.balance = balance
        self.transactions = []

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            self.transactions.append(f"Deposited: {amount}")

    def withdraw(self, amount):
        if amount > 0:
            if self.balance >= amount:
                self.balance -= amount
                self.transactions.append(f"Withdrawn: {amount}")
                return True
            else:
                self.transactions.append("Insufficient balance.")
        return False

    def transfer(self, amount, recipient):
        if amount > 0:
            if self.balance >= amount:
                self.balance -= amount
                recipient.balance += amount
                self.transactions.append(f"Transferred: {amount} to {recipient.name}")
                recipient.transactions.append(f"Received: {amount} from {self.name}")
                return True
            else:
                self.transactions.append("Insufficient balance.")
        return False

    def get_balance(self):
        return self.balance

    def get_transaction_history(self):
        return self.transactions



