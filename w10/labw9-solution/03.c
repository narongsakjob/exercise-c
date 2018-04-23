#include <stdio.h>
#include <math.h>

struct pointXY {
	double x;
	double y;
};

typedef struct pointXY Point;

void printLength(int np, Point p1, Point p2)
{
	double dx = (p1.x > p2.x) ? p1.x - p2.x : p2.x - p1.x;
	double dy = (p1.y > p2.y) ? p1.y - p2.y : p2.y - p1.y;
	double length = sqrt(dx * dx + dy * dy);
	printf("Length from P%d(%.2lf, %.2lf) ", np, p1.x, p1.y);
	printf("to P%d(%.2lf, %.2lf) ", np + 1, p2.x, p2.y);
	printf("is %.2lf", length);
	puts("");
}

int main()
{
	int numPoints, np;
	
	printf("Number of Points: ");
	scanf("%d", &numPoints);
	Point points[numPoints];
	for (np = 1; np <= numPoints; ++np) {
		printf("P%d.X: ", np);
		scanf("%lf", &points[np - 1].x);
		printf("P%d.Y: ", np);
		scanf("%lf", &points[np - 1].y);
	}
	puts("Length:");
	for (np = 0; np < numPoints - 1; ++np) {
		printLength(np + 1, points[np], points[np + 1]);
	}

}