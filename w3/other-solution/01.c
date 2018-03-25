#include <stdio.h>

int main() {
	int b3,b2,b1,b0;
	int d, i;       
	
	scanf("%d", &d);
	
	b0 = d%2;
	i = d/2; 
	b1 = i%2;
	i = i/2; 
	b2 = i%2;
	i = i/2; 
	b3 = i%2;
	
	printf("Binary number of %d is %d%d%d%d.\n", d, b3,b2,b1,b0);
	return 0;
}