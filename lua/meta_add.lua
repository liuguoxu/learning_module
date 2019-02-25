--为元表定义'__add'方法

--获取一个表的最大索引
function getMaxIndex(t)
	local max = 0
	for k,_ in pairs(t) do
		if k > max then
			max = k
		end
	end
	return max
end

--创建一个表，具有'__add'方法
--将'new'表中的项添加到原表后面
function newAddT()
	local t = setmetatable({}, {
	__add = function(my, new)
		for _, v in pairs(new) do
			table.insert(my, getMaxIndex(my)+1, v)
		end
		return my
	end
	})
	return t
end

first = newAddT()
for i = 1, 4 do
	first[i] = i
end

second = {5,6,a="aa",8}

nt = first + second

for k,v in pairs(nt) do
	print(k,v)
end
