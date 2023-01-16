assert(1)

local a = {1, 2, 3, sfasdf = "asdfds", 1}
local c = {1, 2, 3, nil}
local b = {}
local result = next(a, 2)
-- use the function to check whether a table is empty
local result2 = next(b)
print(result)
print(result2)
-- used in string or table's field value
print(rawequal(a[1], c[1]))
local v1 = "sdfsdf"
local v2 = "sdfsdf"
print(rawequal(v1, v2))
print(rawget(a, 2))
for key, value in pairs(a) do
    print(key, value)
end
print(rawlen(c))

local function f(s1, s2)
    print(select(2, s1, s2))
    -- return the total number of extra arguments
    print(select('#', s1, s2))
end
f(1, 3)
print(_VERSION)
