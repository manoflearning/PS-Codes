#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int b_x, b_y;
	int d_x, d_y;
	int end_x, end_y;

	scanf("%d %d %d %d %d %d", &b_x, &b_y, &d_x, &d_y, &end_x, &end_y);

	int ans1 = max(fabs(end_x - b_x), fabs(end_y - b_y));
	int ans2 = fabs(end_x - d_x) + fabs(end_y - d_y);

	if (ans1 < ans2) printf("bessie");
	else if (ans1 > ans2) printf("daisy");
	else printf("tie");

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