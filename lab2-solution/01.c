#include <stdio.h>
int main() {
	int level, year;
	printf("school level of student: ");
	scanf("%d", &level);
	printf("how many of learning: ");
	scanf("%d", &year);
	if( (level > 3 && year > 0) || year > 3 ) {
		printf("YES");
	}else {
		printf("NO");
	}
	return 0;
}