#include <stdio.h>

double add(double a, double b) {
	return a+b;
}

double subtarct(double a, double b) {
	return a-b;
}

double multiply(double a, double b) {
	return a*b;
}

double divide(double a, double b) {
	return a/b;
}

int main() {
	char operator;
    double firstNumber,secondNumber;

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Enter two operands: ");
    scanf("%lf %lf",&firstNumber, &secondNumber);

	switch(operator)
	{
			case '+':
					printf("%.1lf", add(firstNumber, secondNumber));
					break;

			case '-':
					printf("%.1lf", subtarct(firstNumber, secondNumber));
					break;

			case '*':
					printf("%.1lf", multiply(firstNumber, secondNumber));
					break;

			case '/':
					printf("%.1lf", divide(firstNumber, secondNumber));
					break;

			// operator is doesn't match any case constant (+, -, *, /)
			default:
					printf("Error! operator is not correct");
	}

	return 0;
}