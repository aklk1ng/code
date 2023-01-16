local a = {1, 2}
local b = {3, 4}
local c = table.concat(a, ' ')
print(c)

-- table.maxn() is unused after Lua5.2
local function table_maxn(t)
    local mn = nil
    for _, value in pairs(t) do
        if mn == nil then
            mn = value
        end
        if mn < value then
            mn = value
        end
    end
    return mn
end
local tb = {[1] = 2, [2] = 6, [3] = 34, [4] = 5}
print(table_maxn(tb))
print(#tb)

local fibs = { 1, 1 }
setmetatable(fibs, {
  __index = function(values, n) --[[__index is a function predefined by Lua,it is called if key "n" does not exist.]]
    values[n] = values[n - 1] + values[n - 2]  -- Calculate and memoize fibs[n].
    return values[n]
  end
})
print(fibs[3])
