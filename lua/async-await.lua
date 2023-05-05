local co = coroutine

local thread = co.create(function(x, y, z)
  local x, y, z = co.yield('resume the thread')
  return 12
end)

local cont, ret = co.resume(thread, x, y, z)
print(cont, ret)

local function test()
  print('this is a function call')
end

local pong = function(func, callback)
  assert(type(func) == 'function', 'type error :: expected func')
  local thread = co.create(func)
  local step = nil
  step = function(...)
    local stat, ret = co.resume(thread, ...)
    assert(stat, ret)
    if co.status(thread) == 'dead' then
      (callback or function() end)(ret)
    else
      assert(type(ret) == 'function', 'type error :: expected func')
      ret(step)
    end
  end
  step()
end

pong(test)
