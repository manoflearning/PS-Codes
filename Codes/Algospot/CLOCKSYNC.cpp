#include <iostream>
#include <algorithm>
using namespace std;

int Clock[16];
bool moveClock[10][16] = {
	{true, true, true, false, false, false, false, false, false, false, false, false, false, false, false, false},
	{false, false, false, true, false, false, false, true, false, true, false, true, false, false, false, false},
	{false, false, false, false, true, false, false, false, false, false, true, false, false, false, true, true},
	{true, false, false, false, true, true, true, true, false, false, false, false, false, false, false, false},
	{false, false, false, false, false, false, true, true, true, false, true, false, true, false, false, false},
	{true, false, true, false, false, false, false, false, false, false, false, false, false, false, true, true},
	{false, false, false, true, false, false, false, false, false, false, false, false, false, false, true, true},
	{false, false, false, false, true, true, false, true, false, false, false, false, false, false, true, true},
	{false, true, true, true, true, true, false, false, false, false, false, false, false, false, false, false},
	{false, false, false, true, true, true, false, false, false, true, false, false, false, true, false, false}
};

int minClockMove(int count, int flag);

int main() {
	int c;
	scanf("%d", &c);

	for (int test = 0; test < c; test++) {
		for (int i = 0; i < 16; i++)
			scanf("%d", &Clock[i]);

		int ans = minClockMove(0, 0);

		if (ans == 31) printf("-1\n");
		else printf("%d\n", ans);
	}

	return 0;
}

int minClockMove(int count, int flag) {
	//base case
	bool check = true;
	for (int i = 0; i < 16; i++)
		if (Clock[i] % 12 != 0) {
			check = false;
			break;
		}
	if (check) return count;
	
	if (flag == 10) return 31;
	//
	int ans = 31;

	for (int i = 0; i < 4; i++) {
		ans = min(ans, minClockMove(count + i, flag + 1));

		for (int l = 0; l < 16; l++)
			if (moveClock[flag][l]) Clock[l] += 3;
	}
	for (int i = 0; i < 16; i++)
		if (moveClock[flag][i]) Clock[i] -= 12;

	return ans;
}
/*
문제 해법		: 완전 탐색, 하드코딩
접근 방식		:
결정적 깨달음		:
오답 원인		: 1. 
				  2.
*/
//////////////////////////////////////////////////////////////////////
