#include <stdio.h>
int main() {
	int stickers,sale;
	double price;
	scanf("%d", &stickers);
	scanf("%lf", &price);
	if( stickers >= 9  ) {
		sale = 40;
		stickers -= 9;
	}else if( stickers >= 6 ) {
		sale = 30;		
		stickers -= 6;		
	}else if( stickers >= 3 )  {
		sale = 20;	
		stickers -= 3;			
	}else if( stickers == 2 ) {
		sale = 15;	
		stickers -= 2;			
	}else if( stickers == 1 ) {
		sale = 10;	
		stickers -= 1;			
	}else {
		sale = 0;
	}
	price = price - (price*sale/100);
	printf("You get %d percents discount.\n", sale);
	printf("Total amount due is %.2f Baht.\n", price);
	printf("And you have %d stickers left.\n", stickers);
	return 0;
}