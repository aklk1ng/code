print(["".join(x if x == y else " " for y in "1234") for x in "4321"])


def rows(letter):
    letters = [chr(k) for k in range(ord("A"), ord(letter) + 1)]
    alphabet = letters[:-1] + letters[::-1]
    print(alphabet)
    diamond_line = letters[::-1] + letters[1:]
    print(alphabet)
    return ["".join(x if x == y else " " for y in diamond_line) for x in alphabet]


print(rows("E"))
