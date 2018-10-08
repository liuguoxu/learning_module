package main

/*
#include <stdio.h>
typedef int (*intFunc) ();

int bridge_int_func(intFunc f) {
	return f();
}

int fortytwo() {
	return 42;
}
*/
import "C"
import "fmt"

func main() {
	C.puts(C.CString("Hello world!"))

	f := C.intFunc(C.fortytwo)
	fmt.Println(int(C.bridge_int_func(f)))
}
