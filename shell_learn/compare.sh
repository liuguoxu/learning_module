#!/bin/bash


# -lt -gt -eq -ge -le 
int1="19"
int2="18"

echo "int1:"${int1}
echo "int2:"${int2}
if [ $int1 -ge $int2 ]; then
	echo "int1 is bigger than or equal to int2"
else
	echo "int1 is smaller than int2"
fi

# ">" "<" 可以用来比较ASCII字符串大小，但在单中括号中需要转义，双中括号无需转义
str1="a"
str2="b"

if [[ $str1 > $str2 ]]; then
	echo "str1 is bigger than str2"
else
	echo "str1 is smaller than str2"
fi
