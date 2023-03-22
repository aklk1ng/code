import json

data = [{"name": "xxx"}, {"name": "ooo"}, {"name": "jjj"}]
json_str = json.dumps(data, ensure_ascii=False)
print(type(json_str))
print(json_str)

s = '[{"name": "xxx"}, {"name": "ooo"}, {"name": "jjj"}]'
test = json.loads(s)
print(type(test))
print(test)
