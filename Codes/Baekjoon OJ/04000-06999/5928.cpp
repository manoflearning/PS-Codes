#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int d, h, m;
	scanf("%d %d %d", &d, &h, &m);

	int ans = (d * 24 * 60 + h * 60 + m) - (11 * 24 * 60 + 11 * 60 + 11);

	if (ans < 0) printf("-1");
	else printf("%d", ans);

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