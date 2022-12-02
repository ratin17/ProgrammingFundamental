
class Indices:
    def __init__(self, tar, list):
        self.tar = tar
        self.list = list
    def findInd(self):
        for i in range(len(self.list)-1):
            sum = self.list[i] + self.list[i+1]
            if(sum == self.tar):
                print(i+1, i+2)

numbers=[int(x) for x in input("enter comma separated numbers:").split(',')]

target=int(input("Enter target:"))

answer = Indices(target,numbers)
answer.findInd()
