#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

const int MAX = 3500;

int arr[MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//
	int t;
	cin >> t;

	for (int test = 0; test < t; test++) {
		int n, m, k;
		cin >> n >> m >> k;
		
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		//k가 m보다 큰 것은 의미가 없음
		if (m <= k) k = m - 1;

		int ans = 0;
		for (int i = 0; i <= k; i++) {
			int ans2 = INT_MAX;
			for (int l = 0; l <= m - 1 - k; l++) {
				ans2 = min(ans2, max(arr[i + l], arr[(n - 1) - (k - i) - (m - 1 - k - l)]));
			}

			ans = max(ans, ans2);
		}
		cout << ans << '\n';
	}

	return 0;
}