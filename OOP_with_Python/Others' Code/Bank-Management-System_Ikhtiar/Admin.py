class Admin:
    def __init__(self, bank):
        self.bank = bank

    def create_account(self, name, initial_balance=0):
        self.bank.create_account(name, initial_balance)

    def get_total_balance(self):
        return self.bank.get_total_balance()

    def get_total_loan_amount(self):
        return self.bank.get_total_loan_amount()

    def enable_loan_feature(self):
        self.bank.enable_loan_feature()

    def disable_loan_feature(self):
        self.bank.disable_loan_feature()
    
    def is_bankrupt(self):
        self.total_balance < 0