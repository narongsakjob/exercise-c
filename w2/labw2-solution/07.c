#include <stdio.h>
#include <math.h>

int main() {
	int size, pep,cheese, mushroom;
	scanf("%d%d%d%d", &size, &pep, &cheese, &mushroom);
	double area,cost,extra=0;
	if(size == 1) {
		size=10;
	}else if(size == 2) {
		size=16;
	}else {
		size=20;
	}
	extra += ( pep==1 ? 0.5:0 );
	extra += ( cheese==1 ? 0.25:0 );
	extra += ( mushroom==1 ? 0.30:0 );
	area = M_PI*pow(size, 2.0)/4;
	cost = 5 + (2*area) + (extra*area);
	cost *= 1.5;
	printf("Costs %.2f baht.", cost);	
}