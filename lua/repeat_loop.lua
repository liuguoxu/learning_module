a = 10

repeat
	print(a)
	--不支持 a++
	a = a+1
until(a > 15)

print("after loop a:", a)
