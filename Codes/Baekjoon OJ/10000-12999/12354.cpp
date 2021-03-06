#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 50;

int N, arr[MAX + 5], dp[MAX + 5];

int LIS(int n);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;

	for (int test = 1; test <= T; test++) {
		memset(dp, -1, sizeof(dp));

		cin >> N;

		for (int i = 1; i <= N; i++)
			cin >> arr[i];

		int len = -1;
		for(int i=1; i<=N; i++)
			len = max(len, LIS(i));

		cout << "Case #" << test << ": " << N - len << '\n';
	}

	return 0;
}

int LIS(int n) {
	int& ret = dp[n];

	if (ret != -1) return ret;

	ret = 1;

	for (int i = n + 1; i <= N; i++)
		if (arr[n] < arr[i]) ret = max(ret, LIS(i) + 1);

	return ret;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: LIS
결정적 깨달음		: 
시간복잡도		: O(n^2)
오답 원인		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////