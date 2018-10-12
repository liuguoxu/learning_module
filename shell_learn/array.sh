#!/bin/bash

#shell数组
local_mac=jack
list=( $(cat testfile) )

local_list=" ($local_mac,120,0)"

n_list="${list[@]}$local_list"

#list=(${list[@]}$local_mac)


echo "${n_list[@]}"
