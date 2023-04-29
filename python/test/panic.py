import sys


class B(Exception):
    pass


class C(B):
    pass


class D(C):
    pass


# the same class or a base class
for cls in [B, C, D]:
    try:
        raise cls()
    except D:
        print("D")
    except C:
        print("C")
    except B:
        print("B")

try:
    raise Exception("spam", "eggs")
except Exception as inst:
    print(type(inst))
    print(inst.args)
    print(inst)
    x, y = inst.args
    print("x=", x)
    print("y=", y)


for arg in sys.argv[1:]:
    try:
        f = open(arg, "r")
    except OSError:
        print("cannot open:", arg)
    except ValueError:
        print("Could not convert data to an integer.")
    except Exception as err:
        print(f"Unexpected {err=}, {type(err)=}")
    else:
        print(arg, "has", len(f.readlines()), "lines")
        f.close()

print(sys.argv)


def bool_return():
    try:
        return True
    finally:
        return False


print(bool_return())


def divide(x, y):
    try:
        res = x / y
    except ZeroDivisionError:
        print("division by zero!")
    except TypeError:
        print("error type in arguments")
    else:
        print("res is", res)
    finally:
        print("executing finally clause")


divide(2, 1)
divide(2, 0)
divide("2", "1")

try:
    raise TypeError("bad type")
except Exception as e:
    e.add_note("Add some information")
    e.add_note("Add some more information")
    raise
