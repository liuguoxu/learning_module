#!/bin/bash

#测试几种括号替换

a=""

#a为空时将b替换为
b=${a}

echo ${b:-x}
