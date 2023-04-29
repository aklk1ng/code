from dataclasses import dataclass


class Myclass:
    """A simple example class"""

    i = 12345

    def __init__(self, realpart, imagpart):
        """test the init function comment

        Args:
            realpart (r): test1
            imagpart (i): test2
        """
        self.r = realpart
        self.i = imagpart
        # all the instance shared only one variable
        # create a new empty list for each class instance
        self.tricks = []
        self.tricks.append(realpart)

    def f(self):
        return "hello world"

    def test(self, name):
        self.tricks.append(name)
        return "test"


x = Myclass(1, 2)
print(x.r, x.i)
x.r = "create by instance"
# the same name attribute will use the instance not the class
print(x.r, x.i)
print(x.f())
print(x.__doc__)
print(x.__init__.__doc__)
x.test("test")
print(x.tricks)
print(x.__class__)
# isinstance(obj, int) function only return True
# when obj.__class__ is int or some class derived from int
print(isinstance(x, Myclass))

# also lise the issubclass(bool, int) function
print(issubclass(bool, int))  # the bool type is subclass of int
print(issubclass(float, int))  # the float is not a subclass of int


@dataclass
class Employee:
    name: str
    dept: str
    salary: int


test = Employee("cjh", "develop", 1000)
print(test)


class Reverse:
    """Iterator for looping over a sequence backwards"""

    def __init__(self, data):
        self.data = data
        self.index = len(data)

    def __iter__(self):
        return self

    def __next__(self):
        if self.index == 0:
            raise StopIteration
        self.index = self.index - 1
        return self.data[self.index]


rev = Reverse("spam")
for char in rev:
    print(char)
print(rev.__dict__)


# Generator
# Each time next() is called on it, the generator resumes
# where it left off(it remembers all the data values and which statement was last executed)
def reverse(data):
    for index in range(len(data) - 1, -1, -1):
        yield data[index]


data = "golf"
for char in reverse(data):
    print(char)
print(list(data[i] for i in range(len(data) - 1, -1, -1)))

# Generator expression
print(sum(i * i for i in range(5)))  # 30

xvec = [10, 20, 30]
yvec = [7, 5, 3]
print(sum(x * y for x, y in zip(xvec, yvec)))  # 260
