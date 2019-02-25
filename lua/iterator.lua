function myIter(max, start)
	if start < max then
		start = start + 1
		return start, start * start
	end
end

for x, sqr in myIter, 4, 0 do
	print(x, sqr)
end
