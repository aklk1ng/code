import re

s = "python regrex"
# match from the head of text
result = re.match("python", s)
print(result)
print(result.span())
print(result.group())

c = "test python python test regrex"
# find a correct result
search = re.search('python', c)
print(search)
print(search.span())
print(search.group())

# find all correct patterns
find = re.findall("python", c)
print(find)
