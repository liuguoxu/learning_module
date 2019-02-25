handle = function(premature)
	print("time up~")
end

local ok, err = ngx.timer.at(1, handle)

if not ok then
	print("create timer fail, err:", err)
	return
end

