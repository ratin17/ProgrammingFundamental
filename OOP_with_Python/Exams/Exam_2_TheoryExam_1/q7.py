class Subsets:
    def __init__(self, list):
        self.list = list
        self.newList = [[]]

    def makeSet(self):
        for i in range(len(self.list)+1):
            for j in range(i):
                self.newList.append(self.list[j:i])
        
        print(self.newList)

    
        
myList=[int(x) for x in input("enter comma separated numbers:").split(',')]


mySubsets = Subsets(myList)
mySubsets.makeSet()

