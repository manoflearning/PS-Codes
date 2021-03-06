#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

const int MAX = 1000;
const int MIN = 1000 * 1000 * -100 - 1;

int n, m;
int mars[MAX + 1][MAX + 1];

int dp[MAX + 1][MAX + 1][3];

int bigValue(int y, int x, int d);

int main() {
	//reset dp arr
	for (int y = 1; y <= MAX; y++) {
		for (int x = 1; x <= MAX; x++) {
			for (int i = 0; i < 3; i++)
				dp[y][x][i] = MIN;
		}
	}
	//
	cin >> n >> m;

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			cin >> mars[y][x];
		}
	}

	cout << bigValue(1, 1, 0);

	return 0;
}

int bigValue(int y, int x, int d) {
	int& ret = dp[y][x][d];
	//memoization
	if (ret != MIN) return ret;
	//base case
	if (y == n && x == m) return ret = mars[y][x];

	if (y + 1 <= n)
		ret = max(ret, bigValue(y + 1, x, 0));
	if (d != 2 && x + 1 <= m)
		ret = max(ret, bigValue(y, x + 1, 1));
	if (d != 1 && 1 <= x - 1)
		ret = max(ret, bigValue(y, x - 1, 2));

	return ret += mars[y][x];
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 다이나믹 프로그래밍
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////