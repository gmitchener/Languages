### https://www.youtube.com/watch?v=Ej_02ICOIgs ###

import csv

class Item:
    # Class level attributes
    discountedRate = 0.8
    allItems = []

    def __init__(self, name: str, price: float, quantity=0) -> None:
        # Can use assert keyword to set rules for instance level attributes, eg. the price has to be a positive number
        assert price >= 0, f'Price {price} is not valid.'
        assert quantity >= 0, f'Quanity {quantity} is not valid.'

        # Instance level attributes 
        self.name = name
        # Using a double underscore creates private attributes that cannot be read or set, a single underscore makes the attribute read only
        # This is an example of ENCAPSULATION
        self.__price = price
        self.__quantity = quantity 

        # Add each instances to a class attribute list to store all of the instances of this class created
        self.allItems.append(self)

    def __repr__(self) -> str:
        # Can create a representation for an object in this class, typically created to mirror the instance creation
        return f"{self.__class__.__name__}('{self.name}', {self.__price}, {self.__quantity})"

    @classmethod
    def instantiateFromCSV(cls):
        # Class method (doesn't need an instantiated object to run method) to create objects instantiatied from a CSV 
        with open('OOP\oop_items.csv', 'r') as f:
            reader = csv.DictReader(f)
            items = list(reader)
        
        for item in items:
            Item(name=item.get('name'), 
            price=float(item.get('price')), 
            quantity=float(item.get('quantity')))

    @staticmethod
    def isInteger(num):
        # Static methods do not need a self parameter, and do not need an instantiation to be used
        if isinstance(num, float):
            return num.is_integer()
        elif isinstance(num, int):
            return True 
        else: 
            return False

    def calculateTotalPrice(self):
        return self.__price*self.__quantity

    def discountedPrice(self):
        return self.discountedRate*self.__price

    # Getter and setter functions can be made using the property and property.setter decorators
    @property
    def Quantity(self):
        # Getter function to read the value of a private attribute
        return self.__quantity

    @Quantity.setter
    def Quantity(self, quantity):
        self.__quantity = quantity

    @property
    def Price(self):
        return self.__price

    @Price.setter
    def Price(self, price):
        self.__price = price

    def __prepareLink(self):
        link = self.name.replace(' ', '_')
        return f'www.georgiasitems.com/discounts/{link}'

    def __prepareBody(self):
        # Using a double underscore for a method makes it a private method, and can only be accessed from within the class. 
        # This is an example of abstraction, as the user doesn't need to see/ have access to the details of setting up an email to be sent. 
        return f'Hello user, the stock for {self.name} is low! Get it for {self.discountedPrice()} by clicking {self.__prepareLink()}'

    def sendEmail(self):
        return self.__prepareBody()

class Phone(Item):
    allPhones = []

    def __init__(self, name: str, price: float, quantity=0, isBroken=False) -> None:
        assert isinstance(isBroken, bool), 'isBroken must be a boolean type.'

        super().__init__(name, price, quantity)
        self.isBroken = isBroken

        Phone.allPhones.append(self)

    def sendEmail(self):
        return 'Ring ring! ' + super().sendEmail()

class Laptop(Item):
    allLaptops = []

    def __init__(self, name: str, price: float, quantity=0, numpad=True) -> None:
        assert isinstance(numpad, bool), 'numpad must be a boolean type.'

        super().__init__(name, price, quantity)
        self.numpad = numpad

        Laptop.allLaptops.append(self)

    def sendEmail(self):
        return super().sendEmail() + '- Also check out our mouse and keyboard options.'

### CONSTRUCTOR FUNCTION ###

# macbookLaptop = Item('Macbook', 1200, 60)
# iPhone = Item('iPhone', 750, 200)
# cable = Item('Cable', 10, 50)
# mouse = Item('Mouse', 15, 100)
# keyboard = Item('Keyboard', 40, 90)

# print(macbookLaptop.__dict__) # Get a dictionary of instance level attributes 

# macbookLaptop.hasNumpad = True # Can set instance level attributes
# print(macbookLaptop.__dict__)

# print(macbookLaptop.calculateTotalPrice())

# print(Item.discountedRate)
# print(macbookLaptop.discountedPrice())

# print(macbookLaptop.discountedPrice())
# macbookLaptop.discountedRate = 0.7 
# print(macbookLaptop.discountedPrice())
# print(iPhone.discountedRate)

### CLASS VS STATIC METHODS ###

# Item.instantiateFromCSV()
# print(Item.allItems)

# print(Item.isInteger(7.0))

### INHERITANCE ###

macbookLaptop = Laptop('MacBook', 1200, 60)
iPhone = Phone('iPhone', 750, 200, False)
samsung = Phone('Samsung Fire 400', 600, 50)

# print(samsung.calculateTotalPrice())

# print([i for i in Phone.allPhones])
# print([i for i in Laptop.allLaptops])
# print([i for i in Item.allItems])

# print(macbookLaptop.sendEmail()) # The sendEmail function has not been defined specifically in the child class.

### PRIVATE ATTRIBUTES - GETTERS AND SETTERS (ENCAPSULATION) ###

# macbookLaptop = Laptop('MacBook', 1200, 60)
# macbookLaptop.__quantity = 70
# macbookLaptop.Quantity = 65 # Using the getter/setter decorators means that you can write the code as normal (useful to get rid of __quantity)
# print(macbookLaptop.Quantity)

# print(macbookLaptop.discountedPrice())

### ABSTRACTION ###

# print(macbookLaptop.__prepareBody())
# print(macbookLaptop.sendEmail())

### POLYMORPHISM - (many forms) ### 

# print(macbookLaptop.sendEmail())
# print(iPhone.sendEmail())

allItems = Item.allItems
for item in allItems:
    print(item.sendEmail())