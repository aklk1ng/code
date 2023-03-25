print(string.byte('abc'))
print(string.char(97, 98, 99, 100))
print(string.len('fasdf'))
print(string.rep('fasdf', 2))
local line1 = '* - [ ] xxxxx'
local line2 = '* - [x] xxxxx'

local str = 'asdfds134- [x]'
local start, end_col = string.find(str, '%]', 1)
print(start)
print(string.match(str, 'asd', 1))
if string.find(str, '%[%x%]') then
	local new_str = string.gsub(str, 'asd', 'aassdd', 1)
end
print(str)

print('---------------1')

print('line1')
if string.match(line1, '%[%s%]') ~= nil then
	print('- [ ]')
elseif string.match(line1, '') then
	print('- [x]')
end
print('-----------------------')
print('line2')

if string.match(line2, '%[%s%]', 1) ~= nil then
	print('- [ ]')
elseif string.match(line2, '%[%w%]', 1) then
	print('- [x]')
end

print('---------------2')
if string.match(line2, '*- [x]*', 1) ~= nil then
	print('- [x]')
end
print('-----------------------')

local cwd = '~/code/lua'
function split(str, reps)
	local resultStrList = {}
	string.gsub(str, '[^' .. reps .. ']+', function(w)
		table.insert(resultStrList, w)
	end)
	return resultStrList
end

local data = split(cwd, '/')
print(#data)
-- print(string.sub(cwd, pos))
