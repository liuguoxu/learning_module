#!/bin/bash

f1() {
	echo $1

	#函数内的变量需要显示的local，否则默认为全局变量	
	local x="b"
}

start(){
	echo $1
	echo $2
}

stop(){
	echo stop!
}

$*
