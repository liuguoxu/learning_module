function sleep(n)
	os.execute("sleep "..n)
end

function foo(x)
	ret = 0
	local i = 1
	for i =1, x do
		ret = ret + i
		if(i == 2) then
			coroutine.yield("i = 2")
		end

		if(i == 4) then
			coroutine.yield("i == 4")
		end
	end
	return ret
end

co = coroutine.create(foo)
--coroutine新创建是状态时supended
print("1-status:", coroutine.status(co))

--resume第一个返回值`true` or `false`
--第二个返回值，若执行成功返回函数的return值或`yield`参数
--若执行失败返回失败原因
print("1-resume:", coroutine.resume(co, 10))
--执行一次return后状态变为dead，dead的coroutine不能再被resume
print("2-status:", coroutine.status(co))
print("2-resume:", coroutine.resume(co, 10))
print("3-status:", coroutine.status(co))
