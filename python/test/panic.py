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
