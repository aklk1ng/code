set1 = {1, 2, 3}
set2 = {1, 5, 6}
set3 = set1.difference(set2)
set1.difference_update(set2)
set4 = set1.union(set2)
print(set3)
print(set2)
print(set4)
print(len(set4))
for value in set4:
    print(value)
