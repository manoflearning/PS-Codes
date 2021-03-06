#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };
const long double PI = 3.141592653589793238462643383279502884197;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;

	while (tc--) {
		int n; cin >> n;

		vector<int> arr(n), cnt(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			cnt[arr[i]]++;
		}

		int MEX = 0;
		while (cnt[MEX]) MEX++;

		vector<int> ans;

		while (true) {
			//cout << MEX << '\n';
			if (MEX == n) {
				bool unfixed = false;
				for (int i = 0; i < n; i++) {
					if (arr[i] != i) {
						ans.push_back(i + 1);

						int tmp = arr[i];
						arr[i] = MEX;

						cnt[tmp]--;
						cnt[MEX]++;

						MEX = tmp;

						unfixed = true;
						break;
					}
				}

				if (!unfixed) break;
			}
			else if (arr[MEX] != MEX) {
				ans.push_back(MEX + 1);

				int tmp = arr[MEX];
				arr[MEX] = MEX;

				cnt[tmp]--;
				cnt[MEX]++;

				if (tmp < MEX && cnt[tmp] == 0) MEX = tmp;
				else {
					while (cnt[MEX]) MEX++;
				}
			}
		}

		cout << ans.size() << '\n';
		for (int& i : ans) cout << i << ' ';
		cout << '\n';
	}

	return 0;
}