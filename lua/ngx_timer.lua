require "ngx"

handler = function(premature)
	if not premature then
		print("go")
	end
end

local ok,err = ngx.timer.at(2, handler)

if not ok then
	print("create timer failed, err:", err)
end

	
