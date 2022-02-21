class Category:
    def __init__(self, categoryName, categoryBudget):
        self.__Name = categoryName
        self.__Budget = categoryBudget
        self.__Spent = 0
        self.__LogBook = []

    def getName(self):
        return self.__Name

    def getBudget(self):
        return self.__Budget
    def setBudget(self, newBudget):
        self.__Budget = newBudget

    def addSpending(self, spend, description=''):
        self.__Spent += spend 
        self.__LogBook.append({'Amount': spend, 'Description': description})
    def refundSpending(self, refund, description=''):
        self.__Spent -= refund
        self.__LogBook.append({'Amount': -1*refund, 'Description': description})

    def checkSpending(self):
        print(f'You have spent{self.__Spent}.')
        return self.__Spent

    def checkFunds(self):
        if self.__Spent <= self.__Budget:
            moneyLeft = self.__Budget - self.__Spent
            print(f'You have {moneyLeft} left in the {self.__Name} budget.')
            return moneyLeft
        else:
            overdrawn = self.__Spent - self.__Budget
            print(f'You are {overdrawn} overdrawn in the {self.__Name} budget.')
            return -1*overdrawn

    def checkLog(self):
        for item in self.__LogBook:
            print(item)
        return self.__LogBook

def calculateTotalBudget(categories):
    totalBudget = 0
    for c in categories:
        totalBudget += c.getBudget()
    return totalBudget

def calculateBudgetLeft(categories):
    moneyLeft = 0
    for c in categories:
        moneyLeft += c.checkFunds()
    return moneyLeft

def checkAllLogs(categories):
    for c in categories:
        log = c.checkLog()
    return None

### SETTING BUDGETS ###
Food = Category('Food', 100)
Entertainment = Category('Entertainment', 150)
Bills = Category('Bills', 180)
Travel = Category('Travel', 60)
Shopping = Category('Shopping', 100)

categories = [Food, Entertainment, Bills, Travel, Shopping]

### SPENDING ###
Food.addSpending(20, 'Groceries at Tescos')
Entertainment.addSpending(15, 'Night out with the gals')
Travel.addSpending(20, 'Oyster card top up')
Entertainment.refundSpending(5, 'Bought drinks for others')
Shopping.addSpending(5, 'Shampoo')
Bills.addSpending(25, 'Wifi')
Bills.refundSpending(20, 'Shared wifi bill')
Food.addSpending(6, 'Mcdonalds')

### CHECKING BUDGET ###
print('-----Food-----')
Food.checkFunds()
Food.checkLog()

print('---------------------------------------------------------')

checkAllLogs(categories)
print(calculateBudgetLeft(categories))
