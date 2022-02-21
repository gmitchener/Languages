class Dog:
    def __init__(self, name, hairColour, friendliness):
        self.name = name
        self.hairColour = hairColour
        self.friendliness = friendliness
        self.likeWalks = True 

    def sayHello(self):
        if self.friendliness >= 6:
            print(f'My name is {self.name}, woof woof, do you want to play?')
        else:
            print('Woof woof')

class Westie(Dog):
    def __init__(self, name, hairColour, friendliness, skinItchiness):
        super().__init__(name, hairColour, friendliness)
        self.skinItchiness = skinItchiness

class Labrador(Dog):
    def __init__(self, name, hairColour, friendliness, fetchAbility):
        super().__init__(name, hairColour, friendliness)
        self.fetchAbility = fetchAbility

    def fetch(self):
        fetchTime = 60/self.fetchAbility
        print(f'Fetch time: {fetchTime}')

# Luigi = Westie('Luigi', 'white', 10, 7)
# Luigi.sayHello()

Lucy = Labrador('Lucy', 'blonde', 5, 10)
Lucy.sayHello()
Lucy.fetch()