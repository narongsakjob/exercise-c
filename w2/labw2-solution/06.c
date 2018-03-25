#include <stdio.h>

int main() {
	int x,y;
	scanf("%d%d", &x, &y);
	if( x > 0 && y > 0)
	  printf("NE\n");
	else if( x < 0 && y > 0)
	  printf("NW\n");
	else if( x < 0 && y < 0)
	  printf("SW\n");
	else if( x > 0 && y < 0)
	  printf("SE\n");
	else {
	  if( y > 0 ) {
			printf("N\n");
		}else if( y < 0 ) {
			printf("S\n");
		}else if( x > 0 ) {
			printf("E\n");
		}else if( x < 0) {
			printf("W\n");
		}else {
	 		printf("Center\n");	
		}
	}
	return 0;
}