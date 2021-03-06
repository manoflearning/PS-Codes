#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
string now, want;
int dp[100][10][10][10][3];

int find_min(int len, int a1, int a2, int a3, int dir);
int trans(int x);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(dp, -1, sizeof(dp));

	cin >> n >> now >> want;

	cout << min(find_min(0, 0, 0, 0, 0), find_min(0, 0, 0, 0, 1));

	return 0;
}

int find_min(int len, int a1, int a2, int a3, int dir) {
	if (len >= n) return 0;

	int& ret = dp[len][a1][a2][a3][dir];
	//memoization
	if (ret != -1) return ret;
	
	if (want[len] - '0' == trans(now[len] - '0' + a1)) {
		ret = find_min(len + 1, a2, a3, 0, 0);
		ret = min(ret, find_min(len + 1, a2, a3, 0, 1));
		return ret;
	}

	ret = 10 * 100 + 1;

	int ans = 10 * 100 + 1;
	for (int i = 1; i <= 3; i++) {
		if (dir == 0) {
			ans = min(ans, 1 + find_min(len, trans(a1 + i), a2, a3, dir));
			ans = min(ans, 1 + find_min(len, trans(a1 + i), trans(a2 + i), a3, dir));
			ans = min(ans, 1 + find_min(len, trans(a1 + i), trans(a2 + i), trans(a3 + i), dir));
		}
		if (dir == 1) {
			ans = min(ans, 1 + find_min(len, trans(a1 - i), a2, a3, dir));
			ans = min(ans, 1 + find_min(len, trans(a1 - i), trans(a2 - i), a3, dir));
			ans = min(ans, 1 + find_min(len, trans(a1 - i), trans(a2 - i), trans(a3 - i), dir));
		}
	}

	return ret = ans;
}
int trans(int x) {
	return (x + 100) % 10;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 동적계획법
접근 방식		:
결정적 깨달음		:
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////