#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

enum dir {
	left, right, up, down, none
};

int n;
vector< vector<int> > forest;

vector< vector<int> > dp;

int panda_alive(int direct, int y, int x);

int main() {
	scanf("%d", &n);

	forest.resize(n, vector<int>(n));
	dp.resize(n, vector<int>(n, 0));

	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++) {
			scanf("%d", &forest[y][x]);
		}

	int ans = 0;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++) {
			ans = max(ans, panda_alive(dir::none, y, x));
		}

	printf("%d", ans);

	return 0;
}

int panda_alive(int direct, int y, int x) {
	//memoization
	if (dp[y][x] != 0) return dp[y][x];
	//
	dp[y][x] = 1;

	int sam = 0;

	if (x != 0 && direct != dir::right && forest[y][x - 1] > forest[y][x])
		sam = max(sam, panda_alive(dir::left, y, x - 1));
	if (x != n - 1 && direct != dir::left && forest[y][x + 1] > forest[y][x])
		sam = max(sam, panda_alive(dir::right, y, x + 1));
	if (y != 0 && direct != dir::down && forest[y - 1][x] > forest[y][x])
		sam = max(sam, panda_alive(dir::up, y - 1, x));
	if (y != n - 1 && direct != dir::up && forest[y + 1][x] > forest[y][x])
		sam = max(sam, panda_alive(dir::down, y + 1, x));

	dp[y][x] += sam;

	return dp[y][x];
}
/*
문제 해법		: 동적 계획법(top down)
접근 방식		: 
결정적 깨달음	: 
오답 원인		: 1. 
				  2. 
*/
//////////////////////////////////////////////////////////////////////