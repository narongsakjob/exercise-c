#include <stdio.h>
int main() {
	int side1, side2, side3;

	printf("A: ");
	scanf("%d", &side1);
	printf("B: ");
	scanf("%d", &side2);
	printf("C: ");	
	scanf("%d", &side3);	
	if((side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1)) {
    if(side1==side2 && side2==side3) {
      printf("Equilateral triangle.");
    }else if(side1==side2 || side1==side3 || side2==side3) {
      printf("Isosceles triangle.");
    }else {
      printf("Scalene triangle.");
    }
  }else {
    printf("Triangle type invalid.");
  }
	return 0;
}