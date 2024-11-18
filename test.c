#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int a, x, y, z;
	
	x = 10;
	y = 20;
	z = 30;
	
	a = x - y - z;
	printf("%d",a);
	printf("\n");
	a = x + y * z;
	printf("%d",a);
	printf("\n");
	a = x / y + z;
	printf("%.2f",(float)a);
	printf("\n");
	a = x / y / z;
	printf("%.2f",(float)a);
	printf("\n");
	a = x % y % z;
	printf("%d",a);
	printf("\n");
	return 0;
}