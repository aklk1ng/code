local function table_add_keys(old_table)
  assert(type(old_table) == 'table', string.format('Expected table, got %s', type(old_table)))
  local new_table = {}
  for key, _ in pairs(old_table) do
    table.insert(new_table, key)
  end
  return new_table
end

local function table_add_reverse(table)
  assert(type(table) == 'table', string.format('Expected table, got %s', type(table)))
  local new_table = table_add_keys(table)
  for _, key in pairs(new_table) do
    local value = table[key]
    if table[value] then
      error(string.format('Find existing value-- key:%q, value:%q', tostring(key), tostring(value)))
    end
    table[value] = key
  end
  return table
end

local test = {
  ['1'] = 'ast',
  ['1234'] = 'dsfads',
  ['23'] = 'asdfsda',
  ['[ ]'] = '[x]',
}

for key, value in pairs(test) do
  print(key, value)
end
print('-------------------')
test = table_add_reverse(test)
for key, value in pairs(test) do
  print(key, value)
end
