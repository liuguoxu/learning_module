#!/bin/bash

main() {
	trap 'sigint' INT

	while true; do
		echo 1
		sleep 1
	done

	echo end~
}

main
