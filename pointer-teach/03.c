/* Source code to demonstrate, handling of pointers in C program */
#include <stdio.h>
int main(){
  int c, *pc;
	// Wrong! pc is address whereas, c is not an address.
	pc = c;  

	// Wrong! *pc is the value pointed by address whereas, %amp;c is an address.
	*pc = &c; 

	// Correct! pc is an address and, %amp;pc is also an address.
	pc = &c; 

	// Correct! *pc is the value pointed by address and, c is also a value.
	*pc = c;
}
