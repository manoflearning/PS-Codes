#include <iostream>
using namespace std;

void draw_star(int flag, int y, int x);

int main() {
	int n;
	scanf("%d", &n);

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			draw_star(n, y, x);
		}

		printf("\n");
	}

	return 0;
}

void draw_star(int flag, int y, int x) {
	//base case
	if (flag == 3) {
		if (y == 1 && x == 1) printf(" ");
		else printf("*");
		return;
	}
	//
	int check = flag / 3;

	if (check <= y && y < 2 * check && check <= x && x < 2 * check) {
		printf(" ");
		return;
	}

	int s_y, s_x;

	if (y < check) s_y = y;
	else if (check <= y && y < 2 * check) s_y = y - check;
	else if (2 * check <= y) s_y = y - 2 * check;

	if (x < check) s_x = x;
	else if (check <= x && x < 2 * check) s_x = x - check;
	else if (2 * check <= x) s_x = x - 2 * check;

	draw_star(flag / 3, s_y, s_x);
}
/*
문제 해법		: 별찍기, 재귀호출
접근 방식		:
결정적 깨달음	:
오답 원인		: 1. 
				  2.
*/
///////////////////////////////////////////////////////////////////////