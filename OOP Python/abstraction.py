from abc import ABC, abstractmethod

class absClass(ABC):
    def printValue(self, x):
        print('Passed value: ', x)

    @abstractmethod
    def task(self):
        print('We are inside the abstract class task')

class testClass(absClass):
    def task(self):
        print('We are inside the test class task')

class exampleClass(absClass):
    def task(self):
        print('We are inside the example class task')


testObject = testClass()
testObject.task()
testObject.printValue(100)

exampleObject = exampleClass()
exampleObject.task()
exampleObject.printValue(200)

print(f'testObject is an instant of absClass?: {isinstance(testObject, absClass)}')
print(f'exampleObject is an instant of absClass?: {isinstance(exampleObject, absClass)}')