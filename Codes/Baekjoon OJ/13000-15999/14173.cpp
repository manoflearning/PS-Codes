#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int min_x, min_y, max_x, max_y;
	int x1, y1, x2, y2;
	scanf("%d %d %d %d", &min_x, &min_y, &max_x, &max_y);
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

	min_x = min(min_x, x1);
	min_y = min(min_y, y1);
	max_x = max(max_x, x2);
	max_y = max(max_y, y2);
	
	printf("%d", max((max_x - min_x) * (max_x - min_x), (max_y - min_y) * (max_y - min_y)));

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