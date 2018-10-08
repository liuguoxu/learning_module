#!/bin/bash

#echo 测试


#echo `ls`
x=$(ls)
echo $x

#echo -e "ha\nha " # -e 表示进行转义

#echo -e "ha\nha\c" # \c 表示不换行

echo `date`  # 反引号表示显示命令执行结果

p="qwe"
echo yige$p ll
