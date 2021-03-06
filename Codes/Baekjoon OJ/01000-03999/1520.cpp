#include <iostream>
#include <vector>
using namespace std;

enum dir {
	up,
	right,
	down,
	left,
	none
};

int m, n;
vector< vector<int> > map;

vector< vector<int> > dp;

int path_count(int y, int x, int di);

int main() {
	scanf("%d %d", &m, &n);

	map.resize(m, vector<int>(n));
	dp.resize(m, vector<int>(n, -1));

	for (int i = 0; i < m; i++)
		for (int l = 0; l < n; l++) {
			scanf("%d", &map[i][l]);
		}

	printf("%d", path_count(0, 0, dir::none));

	return 0;
}

int path_count(int y, int x, int di) {
	//memoization
	if (dp[y][x] != -1) return dp[y][x];
	//base case
	if (y == m - 1 && x == n - 1) return 1;
	//
	dp[y][x] = 0;

	if (y != 0 && map[y][x] > map[y - 1][x] && di != dir::down)
		dp[y][x] += path_count(y - 1, x, dir::up);
	if (x != n - 1 && map[y][x] > map[y][x + 1] && di != dir::left)
		dp[y][x] += path_count(y, x + 1, dir::right);
	if (y != m - 1 && map[y][x] > map[y + 1][x] && di != dir::up)
		dp[y][x] += path_count(y + 1, x, dir::down);
	if (x != 0 && map[y][x] > map[y][x - 1] && di != dir::right)
		dp[y][x] += path_count(y, x - 1, dir::left);

	return dp[y][x];
}

/*
문제 해법		: 동적 프로그래밍(top down)
접근 방식		:
결정적 깨달음	:
오답 원인		: 1.
				  2.
*/
////////////////////////////////////////////////////////////////////////////////
