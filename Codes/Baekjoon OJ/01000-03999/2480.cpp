#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	if (a == b && b == c) printf("%d", 10000 + a * 1000);
	else if (a == b) printf("%d", 1000 + a * 100);
	else if (b == c) printf("%d", 1000 + b * 100);
	else if (a == c) printf("%d", 1000 + a * 100);
	else printf("%d", max(a, max(b, c)) * 100);

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