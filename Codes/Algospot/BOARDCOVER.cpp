#include <iostream>
using namespace std;

const int block[4][2][2] = { {{0, 1}, {1, 0}}, {{0, 1}, {1, 1}}, {{1, 0}, {1, 1}}, {{1, 0}, {1, -1}} };

int h, w;
char gameboard[20][20];

int countBlock();

int main() {
	int c;
	scanf("%d", &c);

	for (int test = 0; test < c; test++) {
		scanf("%d %d", &h, &w);

		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++) {
				scanf(" %c", &gameboard[y][x]);
			}

		int ans = countBlock();

		printf("%d\n", ans);
	}

	return 0;
}

int countBlock() {
	bool whiteExist = false;

	int y, x;
	for (int i = 0; i < h; i++)
		for (int l = 0; l < w; l++) {
			if (gameboard[i][l] == '.') {
				whiteExist = true;

				y = i, x = l;

				i = h, l = w;
				break;
			}
		}
	
	if (!whiteExist) return 1;
	else {
		int ans = 0;
		
		for (int i = 0; i < 4; i++) {
			if (y + block[i][0][0] < 0 || y + block[i][0][0] >= h) continue;
			if (x + block[i][0][1] < 0 || x + block[i][0][1] >= w) continue;
			if (y + block[i][1][0] < 0 || y + block[i][1][0] >= h) continue;
			if (x + block[i][1][1] < 0 || x + block[i][1][1] >= w) continue;
			
			if (gameboard[y + block[i][0][0]][x + block[i][0][1]] == '#') continue;
			if (gameboard[y + block[i][1][0]][x + block[i][1][1]] == '#') continue;
			
			gameboard[y][x] = '#';
			gameboard[y + block[i][0][0]][x + block[i][0][1]] = '#';
			gameboard[y + block[i][1][0]][x + block[i][1][1]] = '#';

			ans += countBlock();
			
			gameboard[y][x] = '.';
			gameboard[y + block[i][0][0]][x + block[i][0][1]] = '.';
			gameboard[y + block[i][1][0]][x + block[i][1][1]] = '.';
		}
		gameboard[y][x] = '.';

		return ans;
	}
}
/*
문제 해법		: 문제의 요구조건 그대로 구현, 완전탐색
접근 방식		:
결정적 깨달음		:
오답 원인		: 1. 
				  2.
*/
//////////////////////////////////////////////////////////////////////
