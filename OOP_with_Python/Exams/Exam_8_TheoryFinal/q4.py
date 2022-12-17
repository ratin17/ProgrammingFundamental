
class Person:
    def __init__(self,name,height,weight,national_id) -> None:
        self.name=name
        self._height=height
        self._weight=weight
        self.__national_id=national_id
    def _get_height(self):
        return self._height
    def _get_weight(self):
        return self._weight
    def __get_national_id(self):
        return self.__national_id
 
class Student(Person):
    def __init__(self, name, height, weight, national_id,roll,section,marks) -> None:
        super().__init__(name, height, weight, national_id)
        self.roll=roll
        self.section=section
        self.__marks=marks
    def _get_marks(self):
        return self.__marks
   
class Bag:
    def __init__(self,color,company) -> None:
        self.color=color
        self.company=company
    @staticmethod
    def __buy_bag():
        pass
