#include <stdio.h>

void draw_star23(int n);

int main(void) {
	int n;
	
	scanf("%d", &n);
	
	draw_star23(n);
	
	return 0;
}

void draw_star23(int n) {
	int i, l;
	
	for(i=0; i<n; i++)
		printf("*");	
	for(i=0; i<(n-2)*2+1; i++)
		printf(" ");
	for(i=0; i<n; i++)
		printf("*");
	printf("\n");
	
	for(i=n-3; i>=0; i--) {
		for(l=n-2; l>i; l--)
			printf(" ");
		printf("*");
		for(l=0; l<n-2; l++)
			printf(" ");
		printf("*");
		for(l=0; l<i*2+1; l++)
			printf(" ");
		printf("*");
		for(l=0; l<n-2; l++)
			printf(" ");
		printf("*");
		printf("\n");
	}
	
	for(i=0; i<n-1; i++)
		printf(" ");
	printf("*");
	for(i=0; i<n-2; i++)
		printf(" ");
	printf("*");
	for(i=0; i<n-2; i++)
		printf(" ");
	printf("*");
	printf("\n");
	
	for(i=0; i<n-2; i++) {
		for(l=n-2; l>i; l--)
			printf(" ");
		printf("*");
		for(l=0; l<n-2; l++)
			printf(" ");
		printf("*");
		for(l=0; l<i*2+1; l++)
			printf(" ");
		printf("*");
		for(l=0; l<n-2; l++)
			printf(" ");
		printf("*");
		printf("\n");
	}
	
	for(i=0; i<n; i++)
		printf("*");	
	for(i=0; i<(n-2)*2+1; i++)
		printf(" ");
	for(i=0; i<n; i++)
		printf("*");
}



