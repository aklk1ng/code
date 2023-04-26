import re

s = "test python1@gmail.com com"
# result = re.findall(r'([\w-]+(\.[\w-]+)*@(qq|gmail|163)(\.[\w-]+)+)', s)
# result = re.match(r'([\w-]+(\.[\w-]+)*@(qq|gmail|163)(\.[\w-]+)+)', s)
result = re.search(r"([\w-]+(\.[\w-]+)*@(qq|gmail|163)(\.[\w-]+)+)", s)
print(result)
