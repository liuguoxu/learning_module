#!/bin/bash

function main() {
	local action=$1

	case "$1" in
		a)
			echo "you put 'a'!"
			;;

		b)
			echo "you put 'b'!"
			;;

		*)
			echo "what did you put!?"
			;;

	esac
}

main $*
