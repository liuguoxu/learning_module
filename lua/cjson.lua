require "cjson"

t = {}

t.first = 1
t.second = "surprise"

str = cjson.encode(t)

print(str)
