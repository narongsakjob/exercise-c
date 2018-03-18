#include <stdio.h>

int main() {
	double salary,tax;
	scanf("%lf", &salary);
	if(salary < 0) {
		printf("Error");
		return 0;
	} 
	if(salary <= 300000) {
		tax = salary*5/100;
	}else if(salary < 500000) {
		tax = salary*10.0/100.0;
	}else {
		tax = (salary - 300000) * 10.0/100.0;
		tax += 15000;
	}
	printf("%.2f", tax);
	return 0;
}