base = {name = "xiaoming"}

--本表中找不到元素则去metatable设置的__index中找，__index是表则去表中查找；
--若__index是函数，则传入table和key作为参数调用函数
ch = setmetatable({}, {__index = base})

print(ch.name)

ch2 = setmetatable({}, {
	__index = function(table, key)
		if key == "key2" then
			return "you are right!"
		else
			return "who are you ?"
		end
	end
})

print(ch2.name, ch2.key2, ch2.lll)
