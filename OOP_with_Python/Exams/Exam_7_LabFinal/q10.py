
class StudentRepresentative:
    def __init__(self) -> None:
        self.__observers = []

    def attach(self, observer):
        self.__observers.append(observer)

    def add_new_announcement(self, msg):
        self.announce(msg)

    def announce(self, msg):
        for observer in self.__observers:
            observer.update(msg)


class Students:
    def __init__(self, name) -> None:
        self.name = name
    
    def update(self, msg):
        print(f'\nNew Announcement for {self.name}: {msg}\n')


CR = StudentRepresentative()

Mehrab = Students('Mehrab')
Rabbi = Students('Rabbi')
Ratin = Students('Ratin')

CR.attach(Mehrab)
CR.attach(Rabbi)
CR.attach(Ratin)


CR.add_new_announcement("No Quiz in this Week")

CR.add_new_announcement("Soft Computing Quiz on next Sunday")