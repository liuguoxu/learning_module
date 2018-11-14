--定义一个模块
myMod = {}

myMod.const = "my constant"

function myMod.max_num(a, b)
	local ret = nil
	if( a > b ) then
		ret = a
	else
		ret = b
	end

	return ret
end

function myMod.sum2max(max)
	local i = 1
	local sum = 0
	while i <= max do
		sum = sum + i
		i = i + 1
	end
	return sum

end

return myMod
