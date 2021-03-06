#include <iostream>
using namespace std;

const int MAX = 1024;

int arr[MAX][MAX];
int prefixSum[MAX][MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int l = 0; l < n; l++) {
			cin >> arr[i][l];
		}
	}
	//make prefix sum
	prefixSum[0][0] = arr[0][0];
	for (int i = 1; i < n; i++) {
		prefixSum[i][0] = arr[i][0] + prefixSum[i - 1][0];
		prefixSum[0][i] = arr[0][i] + prefixSum[0][i - 1];
	}
	for (int i = 1; i < n; i++) {
		for (int l = 1; l < n; l++) {
			prefixSum[i][l] = arr[i][l];
			prefixSum[i][l] += prefixSum[i - 1][l] + prefixSum[i][l - 1];
			prefixSum[i][l] -= prefixSum[i - 1][l - 1];
		}
	}
	//
	for (int test = 0; test < m; test++) {
		int sx, sy, ex, ey;
		cin >> sy >> sx >> ey >> ex;

		sy--, sx--, ey--, ex--;

		int ans = prefixSum[ey][ex];
		if (sy > 0) ans -= prefixSum[sy - 1][ex];
		if (sx > 0) ans -= prefixSum[ey][sx - 1];
		if (sy > 0 && sx > 0) ans += prefixSum[sy - 1][sx - 1];

		cout << ans << '\n';
	}

	return 0;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1.배열 인덱스는 0부터 시작. 문제의 행렬은 1부터 시작.
				  2. 
*/////////////////////////////////////////////////////////////////////