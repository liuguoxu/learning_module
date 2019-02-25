function myFun()
	print("1")
	coroutine.yield("first")
	print("2")
	coroutine.yield("second")
	print("3")
end

myCo = coroutine.create(myFun)

coroutine.resume(myCo)
print(coroutine.status(myCo))

coroutine.resume(myCo)
print(coroutine.status(myCo))

coroutine.resume(myCo)
print(coroutine.status(myCo))

