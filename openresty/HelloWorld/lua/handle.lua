local cjson = require "cjson"

method = ngx.req.get_method()

local t = {}

t.code = 200
t.status = "success"
t.message = "your method is"..method

ngx,print(cjson.encode(t))
ngx.flush(true)
