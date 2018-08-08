#!/bin/bash

#read参数：
#-p 输入提示文字
#-n 输入长度限制
#-t 输入时间限制
#-s 隐藏输入内容
read -p "请输入密码：" -n 6 -t 5 -s password  

if [ -n "$password" ];then
	echo -e "\npassword is $password"
else
	echo -e "\nno password!"
fi

