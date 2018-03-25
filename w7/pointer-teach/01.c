/* Example to demonstrate use of reference operator in C programming. */
#include <stdio.h>
int main()
{
  int var = 5;
  printf("Value: %d\n", var);
  printf("Address: %u", &var);  //Notice, the ampersand(&) before var.
  return 0;
}

//Value: 5 
//Address: 2686778