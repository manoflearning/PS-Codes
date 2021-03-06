#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAX = 2 * 1e5;

int arr[MAX + 5];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int T; cin >> T;

	while (T--) {
		int N; cin >> N;

		vector<int> cnt(201), loc[201];

		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
			cnt[arr[i]]++;
			loc[arr[i]].push_back(i);
		}

		//
		int ans = -1;
		for (int x = 0; x <= 200; x++) {
			for (int y = 0; y <= 200; y++) {
				if (cnt[x] == 0 || cnt[y] == 0) continue;

				int mid = cnt[x] / 2;
				
				for (int i = 0; i <= mid - 1; i++) {
					int L = lower_bound(loc[y].begin(), loc[y].end(), loc[x][i]) - loc[y].begin();
					int R = lower_bound(loc[y].begin(), loc[y].end(), loc[x][(cnt[x] - 1) - i]) - loc[y].begin() - 1;

					int sam = 2 * (i + 1);
					if (L < loc[y].size() && R < loc[y].size() && L <= R) {
						if (loc[x][i] < loc[y][L] && loc[y][L] < loc[x][cnt[x] - 1]) {
							if (loc[x][i] < loc[y][R] && loc[y][R] < loc[x][cnt[x] - 1]) {
								sam += max(0, R - L + 1);
							}
						}
					}

					ans = max(ans, sam);
				}

				ans = max(ans, cnt[x]);
			}
		}

		cout << ans << endl;
	}

	return 0;
}