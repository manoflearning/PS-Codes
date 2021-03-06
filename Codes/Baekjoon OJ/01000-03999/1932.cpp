#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 500;

int arr[MAX + 5][MAX + 5], dp[MAX + 5][MAX + 5];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//입력
	int N; cin >> N;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= y; x++) {
			cin >> arr[y][x];
		}
	}

	//dp
	dp[1][1] = arr[1][1];
	for (int y = 2; y <= N; y++) {
		dp[y][1] = dp[y - 1][1] + arr[y][1];
		for (int x = 2; x <= y - 1; x++) {
			dp[y][x] = max(dp[y - 1][x - 1], dp[y - 1][x]) + arr[y][x];
		}
		dp[y][y] = dp[y - 1][y - 1] + arr[y][y];
	}

	//출력
	int ans = -1;
	for (int x = 1; x <= N; x++)
		ans = max(ans, dp[N][x]);

	cout << ans;

	return 0;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 동적계획법
결정적 깨달음		:
시간복잡도		: O(n^2)
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////