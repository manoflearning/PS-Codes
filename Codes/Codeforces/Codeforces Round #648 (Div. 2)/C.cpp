#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>

const int INF = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

vi adj[200005];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;

	vi A(N), B(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		adj[A[i]].push_back(i);
	}
	for (int& i : B) cin >> i;

	vi cnt(N);
	for (int i = 0; i < N; i++) {
		for (auto& x : adj[B[i]]) {
			cnt[(x + N - i) % N]++;
		}
	}

	int ans = 0;
	for (int& i : cnt) ans = max(ans, i);

	cout << ans << '\n';

	//naive
	/*int ans = 0;
	for (int k = 0; k < N; k++) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (A[i] == B[(i + k) % N]) cnt++;
		}
		ans = max(ans, cnt);
	}

	cout << ans << '\n';*/

	return 0;
}

/*int tc; cin >> tc;

	while (tc--) {
		int N; cin >> N;

		vector<pii> A(N);
		for (auto& i : A) cin >> i.first;
		for (auto& i : A) cin >> i.second;

		vector<pii> sorted = A;

		sort(sorted.begin(), sorted.end());

		bool Yes = true;
		for (int i = 0; i < N; i++) {
			for (int l = i + 1; l < N; l++) {

			}
		}

		if (Yes) cout << "Yes\n";
		else cout << "No\n";
	}*/