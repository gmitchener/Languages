### POLYMORPHISM ###

class Dog:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def introduce(self):
        print(f'I am a dog and my name is {self.name}, I am {self.age} years old.')

    def speak(self):
        print('Woof woof!')

class Cat:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    
    def introduce(self):
        print(f'I am a cat and my name is {self.name}, I am {self.age} years old.')

    def speak(self):
        print('Meow!')

animals = [Dog('Lucky', 2), Cat('Jingle', 6)]

# for pet in animals:
#     pet.introduce()
#     pet.speak()
### POLYMORPHISM AND INHERITANCE ###

class Enemy:
    def __init__(self, name):
        self.name = name
    
    def scare(self):
        print('I am your enemy, run away!')

class Vampire(Enemy):
    def __init__(self, name):
        super().__init__(name)

    def scare(self):
        print('I am going to suck your blood, run away!')

class Werewolf(Enemy):
    def __init__(self, name):
        super().__init__(name)

    def scare(self):
        print('I am going to bite you, run away!')

enemies = [Vampire('Vlad'), Werewolf('Remus')]

for e in enemies:
    e.scare()