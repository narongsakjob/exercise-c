#include <stdio.h>
int main() {
	char input;
	scanf("%c", &input);

	if( input >= 'a' && input <= 'z' ) {
		printf("Output : lower");
	}else if( input >= 'A' && input <= 'Z') {
		printf("Output : upper");
	}else if( input >= '0' && input <= '9' ) {
		printf("Output : digit");
	}else {
		printf("Output : others");
	}
	return 0;
}