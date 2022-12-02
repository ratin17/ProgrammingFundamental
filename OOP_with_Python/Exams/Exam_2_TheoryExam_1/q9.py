

class sumPow:
    def __init__(self, x, n):
        self.x = x
        self.n = n
    
    def sum(self):
        return (self.x + self.n)
    
    def pow(self):
        return (self.x ** self.n)


instance1 = sumPow(2, 3)
print(instance1.sum())
print(instance1.pow())