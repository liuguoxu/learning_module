#!/bin/bash

f1() {
	echo $1

	#函数内的变量需要显示的local，否则默认为全局变量	
	local x="b"
}

start(){
	echo start!
	f1 "a"
	echo $x
}

stop(){
	echo stop!
}

$1
