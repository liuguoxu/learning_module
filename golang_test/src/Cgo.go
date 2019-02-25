package main

/*
#include <stdio.h>
typedef int (*intFunc) (int x);

int bridge_int_func(intFunc f, int x) {
	return f(x);
}

int fortytwo(int x) {
	return 42+x;
}
*/
import "C"
import "fmt"

func main() {
	C.puts(C.CString("Hello world!"))

	f := C.intFunc(C.fortytwo)
	fmt.Println(int(C.bridge_int_func(f, 3)))
}
