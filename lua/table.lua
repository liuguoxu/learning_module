x = 1
--用这种方式初始化table的key只能是字符串，并且不能用引号
tab1 = {x = "val1", key2 = "val2", "val3"}
print(tab1)

for k,v in pairs(tab1) do
	print("before table1:"..k.."-"..v)
end

--用方括号或点都可以取出table中的值
print(tab1["key1"])
print(tab1.key1)
tab1.key1 = nil

for k,v in pairs(tab1) do
	print("after table1:"..k.."-"..v)
end

tab2 = {"a", "b", "c"}
for k,v in pairs(tab2) do
	print("tab2:"..k.."-"..v)
end

--数字索引只能用方括号
print(tab2[1])
--print(tab2.1)

tab3 = tab2

for k,v in pairs(tab3) do
	print(k, v)
end

tab2 = nil

for k,v in pairs(tab3) do
	print(k, v)
end


