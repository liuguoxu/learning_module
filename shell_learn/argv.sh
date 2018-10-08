#!/bin/bash

func1() {
	echo you are in func1
}

func2() {
	echo you are in func2
}

echo shell 文件名：$0
echo 第一个参数：$1
echo 第二个参数：$2
echo 全部参数：$*

$1
