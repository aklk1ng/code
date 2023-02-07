print(string.byte("abc"))
print(string.char(97, 98, 99, 100))
print(string.len("fasdf"))
print(string.rep("fasdf", 2))

local str = "asdfds134"
if string.find(str, "asd") then
    local new_str = string.gsub(str, "asd", "aassdd", 1)
    str = new_str
end
print(str)
