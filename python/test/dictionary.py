dict1 = {1: 2, "white": "fsdf"}
print(dict1[1])
print(dict1["white"])

for k, v in range(dict1):
    if v == 2:
        del dict1[k]

print(dict1)
