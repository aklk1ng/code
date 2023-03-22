Dog = {}
function Dog:new()
	-- newobj is a instance of class Dog
	local newobj = { sound = "woof" }
	self.__index = self
	return setmetatable(newobj, self)
end

function Dog:makeSound()
	print("I say " .. self.sound)
end

local myDog = Dog:new()
myDog:makeSound()
