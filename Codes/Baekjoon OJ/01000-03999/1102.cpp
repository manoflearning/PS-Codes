#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int n, p;
int elec[16][16];
string ON;

vector<int> dp((1 << 16), -1);
bool visited[16];

int MIN(int cnt);
int dper();
int minCOST(int x);

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int l = 0; l < n; l++) {
			cin >> elec[i][l];
		}
	}

	cin >> ON >> p;
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (ON[i] == 'Y') {
			visited[i] = true;
			cnt++;
		}
	}

	int ans = MIN(cnt);
	if (ans >= 10000) cout << "-1";
	else cout << ans;

	return 0;
}

int MIN(int cnt) {
	int& ret = dp[dper()];
	//memoization
	if (ret != -1) return ret;
	//base case
	if (cnt >= p) return 0;

	int RET = 10000;
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;

		visited[i] = true;
		RET = min(RET, minCOST(i) + MIN(cnt + 1));
		visited[i] = false;
	}

	return ret = RET;
}
int dper() {
	int ret = 0;
	for (int i = 0; i < n; i++)
		if (visited[i]) ret += (1 << i);
	return ret;
}
int minCOST(int x) {
	int ret = 10000;
	for (int i = 0; i < n; i++)
		if (visited[i] && i != x) {
			ret = min(ret, elec[i][x]);
		}
	return ret;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 비트마스크, dp
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 불가능한 경우를 예외처리 하지 않음
				  2. 
*/////////////////////////////////////////////////////////////////////