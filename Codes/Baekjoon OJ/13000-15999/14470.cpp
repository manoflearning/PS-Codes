#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, e;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

	int ans = 0;

	if (a < 0) {
		ans += -(c * a);
		a = 0;
	}

	if (a == 0) ans += d;

	ans += (b - a) * e;

	printf("%d", ans);
	
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