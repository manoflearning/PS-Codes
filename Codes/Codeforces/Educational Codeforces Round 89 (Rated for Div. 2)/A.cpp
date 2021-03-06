#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vc vector<char>
#define vs vector<string>
#define vpi vector<pii>
#define vpl vector<pll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vvd vector<vector<double>>
#define vvc vector<vector<char>>
#define vvs vector<vector<string>>
#define vvpi vector<vector<pii>>
#define vvpl vector<vector<pll>>

const int INF = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

int a, b;

int bSearch(int L, int R);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;

	while (tc--) {
		cin >> a >> b;

		if (a > b) swap(a, b);

		if (a <= b / 2) cout << a << '\n';
		else {
			int cnt = bSearch(0, INF);

			a -= cnt * 2, b -= cnt;
			int ans = cnt + a;
			
			cout << ans << '\n';
		}
	}

	return 0;
}


int bSearch(int L, int R) {
	if (L == R) return L;

	int mid = (L + R) >> 1;

	if (a - 2 * mid <= (b - mid) / 2) return bSearch(L, mid);
	else return bSearch(mid + 1, R);
}