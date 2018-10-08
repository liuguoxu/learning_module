#!/bin/bash

query_string="p1=123 p2=456 p3=789"

main() {
	local $query_string

	for i in $p1 $p2 $p3;do
		echo $i
	done
}

main
