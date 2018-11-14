local function max_num(a, b)
	local ret = nil
	if( a > b ) then
		ret = a
	else
		ret = b
	end

	return ret
end

local function sum2max(max)
	local i = 1
	local sum = 0
	while i <= max do
		sum = sum + i
		i = i + 1
	end
	return sum

end

local function main()
	--求两个数的最大值
	local x,y  = -12, 20
	print("The maximum of "..x.." and "..y.." is "..max_num(x,y))
	
	--求从1到max的和
	local max = 10
	print("The sum of 1 to "..max.." is "..sum2max(max))
end

main()
