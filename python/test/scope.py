def scope_test():
    def do_local():
        spam = "local spam"

    def do_nonlocal():
        nonlocal spam
        spam = "nonlocal spam"

    def do_global():
        global spam
        spam = "global spam"

    spam = "test spam"
    do_local()
    print("after local assignment:", spam)
    do_nonlocal()
    print("after nonlocal assignment:", spam)
    do_global()
    print("after global assignment:", spam)


scope_test()
print(spam)
