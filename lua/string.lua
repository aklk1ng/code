print(string.byte("abc"))
print(string.char(97, 98, 99, 100))
print(string.len("fasdf"))
print(string.rep("fasdf", 2))
local line1 = "* - [ ] xxxxx"
local line2 = "* - [x] xxxxx"

local str = "asdfds134- [x]"
if string.find(str, "%[%x%]") then
    local new_str = string.gsub(str, "asd", "aassdd", 1)
    str = new_str
end
print(str)

print("---------------1")

print("line1")
if string.match(line1, "%[%s%]") ~= nil then
    print("- [ ]")
elseif string.match(line1, "") then
    print("- [x]")
end
print("-----------------------")
print("line2")

if string.match(line2, "%[%s%]", 1) ~= nil then
    print("- [ ]")
elseif string.match(line2, "%[%w%]", 1) then
    print("- [x]")
end

print("---------------2")
if string.match(line2, "*- [x]*", 1) ~= nil then
    print("- [x]")
end
