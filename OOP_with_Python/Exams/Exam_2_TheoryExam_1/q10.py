
import math

class Distance:
    def __init__(self,x1,y1,x2,y2):
        self.x1=x1
        self.y1=y1
        self.x2=x2
        self.y2=y2

    def mesDistance(self):
        print(math.sqrt((self.x1-self.x2)**2+(self.y1-self.y2)**2))

    
twoPints=Distance(4, 0, 3, 0)

twoPints.mesDistance()