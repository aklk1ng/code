import json
import math
from functools import wraps

buffer = {"aa": 12, "bb": 32}

with open("test.txt", "w+") as file:
    file.write(json.dumps(buffer))

with open("test.txt", "r+") as file:
    contents = file.read()
    print(contents)

with open("test.txt", "r+") as file:
    contents = json.load(file)
    print(contents)

iterable = buffer.keys()
# create a iterator by an object that can remember the state
iterater = iter(iterable)
print(iterater.__next__())
print(next(iterater))
# print(next(iter ter))
# grab all the elements of an iterable or iterator
print(list(iterater))  # => [] because state is saved


# define a variable number of positional arguments
# and keyword arguments
def all_the_args(*args, **kwargs):
    print(args)
    print(kwargs)


all_the_args(1, 2, a=3, b=4)


print(list(map(max, [1, 2, 3], [4, 2, 0])))
print(list(filter(lambda x: x > 5, [3, 4, 5, 6, 7])))
# List comprehension stores the output as a list(which itself may be nested)
print([x for x in [3, 4, 5, 6, 7] if x > 4])
print({x for x in "abcdef" if x not in "abc"})
print({x: x**2 for x in range(5)})
print(math.sqrt(16))
# find out which functions and attributes
# are defined in module
# and local folder has priority oever Python's built-in libraries
print(dir(math))


# Generators
def double_numbers(iterable):
    for i in iterable:
        yield i + i


for i in double_numbers(range(1, 9000)):
    print(i)
    if i >= 30:
        break
values = (-x for x in [1, 2, 3, 4, 5])
print(list(values))


# Decorators
# If say_please is True then it will change the returned message
def beg(target_function):
    @wraps(target_function)
    def wrapper(*args, **kwargs):
        msg, say_please = target_function(*args, **kwargs)
        if say_please:
            return f"{msg} Please! I am poor :("
        return msg

    return wrapper


@beg
def say(say_please=False):
    msg = "Can you buy me a beer?"
    return msg, say_please


print(say())
print(say(say_please=True))


class Human:
    species = "H. sapiens"

    def __init__(self, name):
        self.name = name
        self._age = 0

    def say(self, msg):
        print(f"{self.name}: {msg}")

    def sing(self):
        return "yo...yo..."

    # A class method is shared among all instances
    # They are called with the calling class as the first arguments
    @classmethod
    def get_species(cls):
        return cls.species

    # A static method is called without a calss or instance reference
    @staticmethod
    def grunt():
        return "*grunt*"

    #  A property is just like a getter
    # it turns the method age() into a read-only attribute of the same name
    # There's no need to write trivial getters and setters in Python, though
    @property
    def age(self):
        return self._age

    # This allows the property to be set
    @age.setter
    def age(self, age):
        self._age = age

    # This allows the property to be deleted
    @age.deleter
    def age(self):
        del self._age


class Bat:
    species = "Baty"

    def __init__(self, can_fly=True):
        self.fly = can_fly

    def say(self, msg):
        msg = "... ... ..."
        return msg

    def sonar(self):
        return "))) ... ((("


class Superhero(Human):
    species = "Superhuman"

    def __init__(
        self, name, movie=False, superpowers=["super strength", "bulletproffing"]
    ):
        self.fictional = True
        self.movie = movie
        self.superpowers = superpowers
        super().__init__(name)

    def sing(self):
        return "Dun, dun, DUN!"

    def boast(self):
        for power in self.superpowers:
            print(f"I get the power of {power}")


class Batman(Superhero, Bat):
    def __init__(self, *args, **kwargs):
        Superhero.__init__(
            self, "anonymous", movie=True, superpowers=["Wealthy"], *args, **kwargs
        )
        Bat.__init__(self, *args, can_fly=False, **kwargs)
        self.name = "Sad Affleck"

    def sing(self):
        return "nan nan nan nan batman!"


if __name__ == "__main__":
    i = Human(name="cjh")
    i.say("hi")
    j = Human(name="xxoo")
    j.say("hello")
    i.say(i.get_species())
    j.say(j.get_species())

    print(Human.grunt())
    print(i.grunt())

    i.age = 42
    i.say(i.age)
    del i.age

    sup = Superhero(name="Jack")
    if isinstance(sup, Human):
        print("I am human")

    if type(sup) is Superhero:
        print("I am a superhero")

    # Get the method resolution search order used by both
    # getattr() and super()
    # This attribute is dynamic and can be updated
    print(Superhero.__mro__)

    print(sup.get_species())
    print(sup.sing())
    sup.say("Spoon")
    sup.boast()

    sup.age = 32
    print(sup.age)
    print("Am i Oscar eligible? " + str(sup.movie))

    b = Batman()
    print(Batman.__mro__)
    print(b.sing())
    b.say("i agree")
    print(b.sonar())

    pairs = [(1, "one"), (2, "two"), (3, "three"), (4, "four")]
    pairs.sort(key=lambda pair: pair[1])
    print(pairs)

    matrix = [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 10, 11, 12],
    ]
    for cow in matrix:
        print(cow[0])
    print(list(zip(*matrix)))
    transpose_matrix = [[row[i] for row in matrix] for i in range(4)]
    print(transpose_matrix)
