#include <iostream>
using namespace std;

int paper[2187][2187];
int ans[3];

void cut_paper(int start_y, int start_x, int size);

int main() {
	int n;
	scanf("%d", &n);

	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++) {
			scanf("%d", &paper[y][x]);
		}

	cut_paper(0, 0, n);

	printf("%d\n%d\n%d", ans[0], ans[1], ans[2]);

	return 0;
}

void cut_paper(int start_y, int start_x, int size) {
	int flag = paper[start_y][start_x];
	bool check = true;

	for (int y = start_y; y < start_y + size; y++)
		for (int x = start_x; x < start_x + size; x++) {
			if (paper[y][x] != flag) {
				check = false;
				
				y = start_y + size;
				x = start_x + size;
				break;
			}
		}
	
	if (check) ans[flag + 1]++;
	else {
		int Rsize = size / 3;

		cut_paper(start_y, start_x, Rsize);
		cut_paper(start_y, start_x + Rsize, Rsize);
		cut_paper(start_y, start_x + 2 * Rsize, Rsize);
		cut_paper(start_y + Rsize, start_x, Rsize);
		cut_paper(start_y + Rsize, start_x + Rsize, Rsize);
		cut_paper(start_y + Rsize, start_x + 2 * Rsize, Rsize);
		cut_paper(start_y + 2 * Rsize, start_x, Rsize);
		cut_paper(start_y + 2 * Rsize, start_x + Rsize, Rsize);
		cut_paper(start_y + 2 * Rsize, start_x + 2 * Rsize, Rsize);
	}
}
/*
문제 해법		: 분할정복
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 
				  2. 
*/
//////////////////////////////////////////////////////////////////////