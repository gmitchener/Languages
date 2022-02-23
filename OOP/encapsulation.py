class Dog:
    def __init__(self, name, age, health):
        self.name = name
        self.age = age
        self.health = health

lucky = Dog('Lucky', 2, 9)
# print(lucky.age)
# lucky.age = 3
# print(lucky.age)

class Person:
    def __init__(self, name, age, health):
        self.name = name
        self.__age = age
        self.__health = health

    def getAge(self):
        return self.__age
    def setAge(self, age):
        self.__age = age

    def getHealth(self):
        return self.__health
    def setHealth(self, health):
        self.__health = health
    
matt = Person('matt', 25, 10)
matt.setAge(26)
print(matt.getAge())

