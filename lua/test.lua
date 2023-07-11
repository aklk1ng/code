local str = 'per13_fsdf'
local pat = '\\<fsdf8433\\>'
local test = '!("++++++++++++++++++++++++++++");'

if str:match('^%w+') then
  print('str')
end
if pat:match('^%w+') then
  print('pat')
end
if test:find('!("++++++++++++++++++++++++++++");') then
  print('test')
end

if string.find('!(+)', '!(+)') then
  print('string')
end
