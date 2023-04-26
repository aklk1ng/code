import random
import time


def outer(func):
    def inner():
        print("Go")
        func()
        print("Over")

    return inner


# decorator
@outer
def sleep():
    print("Sleep...")
    time.sleep(random.randint(1, 5))


sleep()
