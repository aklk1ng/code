class Animal:
  def speak(self):
    pass


class Dog(Animal):
  def speak(self):
    print("Dog")


class Cat(Animal):
  def speak(self):
    print("Cat")


def make_noise(animal: Animal):
  animal.speak()


dog = Dog()
cat = Cat()
make_noise(dog)
make_noise(cat)
