#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int INF = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

int h, c, t;
double m;
double diff;

ll bSearch(int L, int R);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(9);
	int T; cin >> T;

	while (T--) {
		cin >> h >> c >> t;

		m = ((double)h + c) / 2;

		if (t <= m) {
			cout << 2 << '\n';
			continue;
		}

		diff = ((double)h - c);
		
		ll i = bSearch(0, INF);

		double tem = diff * (i + 1) / (2 * i + 1) + c;
		double ntem = diff * (i + 2) / (2 * (i + 1) + 1) + c;
		//cout << tem << ' ' << ntem << '\n';
		//cout << 2 * i + 1 << '\n';
		if (fabs(ntem - t) < fabs(tem - t)) cout << 2 * (i + 1) + 1 << '\n';
		else cout << 2 * i + 1 << '\n';
	}

	return 0;
}

ll bSearch(int L, int R) {
	if (L == R) return L;

	ll mid = (L + R + 1) / 2;

	double tem = diff * (mid + 1) / (2 * mid + 1) + c;

	if (t <= tem) return bSearch(mid, R);
	else return bSearch(L, mid - 1);
}