#include <iostream>
using namespace std;

char pic[64][64];

string compress(int s_x, int s_y, int size);

int main() {
	int n;
	scanf("%d", &n);

	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++) {
			scanf(" %c", &pic[y][x]);
		}

	cout << compress(0, 0, n);

	return 0;
}

string compress(int s_x, int s_y, int size) {
	bool check = true;

	for (int y = s_y; y < s_y + size; y++)
		for (int x = s_x; x < s_x + size; x++) {
			if (pic[y][x] != pic[s_y][s_x]) {
				check = false;
				break;
			}
		}
	//base case
	if (check) return string(1, pic[s_y][s_x]);

	return string("(") + compress(s_x, s_y, size / 2) + compress(s_x + size / 2, s_y, size / 2)
		+ compress(s_x, s_y + size / 2, size / 2) + compress(s_x + size / 2, s_y + size / 2, size / 2) + string(")");
}
/*
문제 해법		: 분할정복
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 
				  2. 
*/
//////////////////////////////////////////////////////////////////////