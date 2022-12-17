
class Parent:

    def parentFunc(self):
        print("Inside parent")


class Father:

    def fatherFunc(self):
        print("Inside Father")


class Mother:

    def motherFunc(self):
        print("Inside Mother")




class Child(Parent):

    def childFunc(self):
        print("Inside Child")


class GrandChild(Child):

    def grandChildFunc(self):
        print("Inside GrandChild")



class Son(Parent):

    def sonFunc(self):
        print("Inside Son")

