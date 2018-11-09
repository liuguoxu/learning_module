function printPairs(tab, printFunc)
	for k,v in pairs(tab) do
		printFunc(k, v)
	end
end

--将函数作为变量传递
myFunc = function(k, v)
	print(k.."="..v)
end

tab = {k1 = "v1", k2 = "v2"}

printPairs(tab, myFunc)
