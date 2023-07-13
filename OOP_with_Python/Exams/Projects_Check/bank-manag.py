class User:
    def __init__(self, name, id):
        self.name = name
        self.id = id
        self.balance = 0
        self.loan = 0
        self.transactions = []

    def deposit(self, amount):
        self.balance += amount
        self.transactions.append(f"Deposit: +{amount}")

    def get_max_withdrawable_amount(self, bank_balance):
        max_withdrawal = self.balance - self.loan
        max_bank_balance = bank_balance - self.loan
        return min(max_withdrawal, max_bank_balance)

    def withdraw(self, amount, bank_balance):
        if amount > bank_balance - self.loan:
            print("Bank is bankrupt. Withdrawal not allowed.")
        else:
            if amount <= self.balance:
                self.balance -= amount
                self.transactions.append(f"Withdrawal: -{amount}")
                print("Withdrawal successful.")
                return amount
            else:
                remaining_loan_amount = self.loan - (amount - self.balance)
                if remaining_loan_amount >= 0:
                    self.loan = remaining_loan_amount
                    self.balance = 0
                    self.transactions.append(f"Withdrawal: -{amount} (from loan)")
                    print("Withdrawal successful from the loan.")
                    return amount
                else:
                    print("Insufficient funds and loan amount!")

        return 0


    def transfer(self, amount, receiver, bank_balance, bank_bankrupt):
        if bank_bankrupt:
            print("Bank is bankrupt. Transfer not allowed.")
        elif self.balance >= amount:
            self.balance -= amount
            receiver.balance += amount
            self.transactions.append(f"Transfer: -{amount} to {receiver.name}")
            receiver.transactions.append(f"Transfer: +{amount} from {self.name}")
        else:
            print("Insufficient funds!")

    def take_loan(self, loan_feature_enabled, bank_balance):
        if loan_feature_enabled:
            if bank_balance <= 0:
                print("Bank is bankrupt. Loan not allowed.")
                return
            max_loan_amount = 2 * self.balance
            if self.loan + max_loan_amount <= bank_balance:
                self.loan += max_loan_amount
                self.balance += max_loan_amount
                self.transactions.append(f"Loan taken: +{max_loan_amount}")
                print("Loan taken successfully.")
            else:
                print("Loan amount exceeds the bank's total balance.")
        else:
            print("The loan feature is turned off.")

    def show_balance(self):
        return self.balance

    def show_transactions(self):
        return self.transactions


class Admin:
    def __init__(self):
        self.users = []
        self.loan_feature_enabled = True
        self.bank_balance = 1000

    def create_account(self, name, id):
        for user in self.users:
            if user.name == name or user.id == id:
                print("User with the same name or ID already exists.")
                return
        user = User(name, id)
        self.users.append(user)
        print("Account created successfully.")

    def total_balance(self):
        total = self.bank_balance - sum(user.loan for user in self.users)
        return total

    def is_bankrupt(self):
        return self.total_balance() <= 0


admin = Admin()
active_user = None
active_admin = None

while True:
    print("\n----- Banking Management System -----")
    print("1. User")
    print("2. Admin")
    print("3. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        print("\n----- User -----")
        print("1. Create an account")
        print("2. Login to an existing account")
        user_choice = int(input("Enter your choice: "))

        if user_choice == 1:
            name = input("Enter your name: ")
            id = input("Enter your ID: ")
            admin.create_account(name, id)

        elif user_choice == 2:
            if active_user is None:
                name = input("Enter your name: ")
                id = input("Enter your ID: ")
                user = None
                for u in admin.users:
                    if u.name == name and u.id == id:
                        user = u
                        break

                if user is None:
                    print("User does not exist.")
                    continue

                active_user = user
            else:
                print("You are already logged in as a user.")

            while active_user:
                print("\n1. Deposit")
                print("2. Withdraw")
                print("3. Transfer")
                print("4. Check balance")
                print("5. Check transaction history")
                print("6. Take a loan")
                print("7. Logout")
                user_choice = int(input("Enter your choice: "))

                if user_choice == 1:
                    amount = float(input("Enter the amount to deposit: "))
                    admin.bank_balance += amount
                    active_user.deposit(amount)
                    print("Amount deposited successfully.")

                # Inside the user's interaction loop
                elif user_choice == 2:
                    amount = float(input("Enter the amount to withdraw: "))
                    withdrawn_amount = active_user.withdraw(amount, admin.bank_balance)
                    admin.bank_balance -= withdrawn_amount


                elif user_choice == 3:
                    receiver_name = input("Enter the name of the receiver: ")
                    receiver = None
                    for u in admin.users:
                        if u.name == receiver_name:
                            receiver = u
                            break

                    if receiver is None:
                        print("Receiver does not exist.")
                        continue

                    amount = float(input("Enter the amount to transfer: "))
                    active_user.transfer(
                        amount, receiver, admin.bank_balance, admin.is_bankrupt()
                    )
                    print("Amount transferred successfully.")

                elif user_choice == 4:
                    balance = active_user.show_balance()
                    print(f"Available balance: {balance}")

                elif user_choice == 5:
                    transactions = active_user.show_transactions()
                    print("Transaction History:")
                    for transaction in transactions:
                        print(transaction)

                elif user_choice == 6:
                    active_user.take_loan(
                        admin.loan_feature_enabled, admin.bank_balance
                    )

                elif user_choice == 7:
                    active_user = None

                else:
                    print("Invalid choice. Please try again.")

    elif choice == 2:
        if active_admin is None:
            while True:
                print("\n----- Admin -----")
                print("1. Create account")
                print("2. Check total balance")
                print("3. Check if the bank is bankrupt")
                print("4. Turn on/off loan feature")
                print("5. Set bank's total balance")
                print("6. Logout")
                admin_choice = int(input("Enter your choice: "))

                if admin_choice == 1:
                    name = input("Enter user's name: ")
                    id = input("Enter user's ID: ")
                    admin.create_account(name, id)

                elif admin_choice == 2:
                    total_balance = admin.total_balance()
                    print(f"Total balance in the bank: {total_balance}")

                elif admin_choice == 3:
                    if admin.is_bankrupt():
                        print("The bank is bankrupt.")
                    else:
                        print("The bank is not bankrupt.")

                elif admin_choice == 4:
                    print("1. Turn on loan feature")
                    print("2. Turn off loan feature")
                    loan_choice = int(input("Enter your choice: "))

                    if loan_choice == 1:
                        admin.loan_feature_enabled = True
                        print("Loan feature turned on.")
                    elif loan_choice == 2:
                        admin.loan_feature_enabled = False
                        print("Loan feature turned off.")
                    else:
                        print("Invalid choice.")

                elif admin_choice == 5:
                    balance = float(input("Enter the bank's total balance: "))
                    admin.bank_balance = balance
                    print("Bank's total balance set successfully.")

                elif admin_choice == 6:
                    break

                else:
                    print("Invalid choice. Please try again.")

            active_admin = None
        else:
            print("You are already logged in as an admin.")

    elif choice == 3:
        print("Thank you for using the Banking Management System.")
        break

    else:
        print("Invalid choice. Please try again.")