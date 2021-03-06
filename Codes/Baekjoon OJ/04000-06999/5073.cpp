#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a[3];
	
	while (true) {
		scanf("%d %d %d", &a[0], &a[1], &a[2]);

		if (a[0] == 0 && a[1] == 0 && a[2] == 0) break;

		sort(a, a + 3);

		if (a[2] >= a[0] + a[1]) printf("Invalid\n");
		else if (a[0] == a[1] && a[1] == a[2]) printf("Equilateral\n");
		else if (a[0] == a[1] || a[1] == a[2]) printf("Isosceles\n");
		else printf("Scalene\n");
	}

	return 0;
}
/*
문제 해법		: 
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 
				  2. 
*/
//////////////////////////////////////////////////////////////////////