class Dog:
    def walk(self):
        return "*walking*"
    def speak(self):
        return "Woof!"
    
class JackRussellTerrier(Dog):
     def talk(self):
         return super().speak()

bobo = JackRussellTerrier()
print(bobo.talk())