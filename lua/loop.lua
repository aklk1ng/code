for i = 10, 1, -1 do
	print(i)
end
a = { 1, 2, 3 }
local f = function(x)
	return x * x
end
print(f(10))
-- _G is a special table of all globals
print(_G['a'][1])
print(_G['_G'] == _G)
-- #a is the siez of a for lists(actually table)
print(#a)

local a = nil
print(not nil)
print(os.getenv('HOME'))
