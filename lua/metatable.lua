local f1 = { a = 1, b = 2 }
for key, value in pairs(f1) do
  print(key, value)
end
local f2 = { a = 2, b = 3 }
local metafraction = {}
function metafraction.__add(t1, t2)
  local sum = {}
  sum.b = t1.b + t2.b
  sum.a = t1.a + t2.a
  return sum
end

setmetatable(f1, metafraction)
setmetatable(f2, metafraction)
local s = f1 + f2
-- print(s['a'], s['b'])
print(s.a, s.b)

local defaultFavs = { animal = 'gru', food = 'donuts' }
local myFavs = { food = 'pizza' }
setmetatable(myFavs, { __index = defaultFavs })
local print_eatenBy = myFavs.animal
print(print_eatenBy)
print(getmetatable(print_eatenBy))
