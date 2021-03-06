#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };
const int MAXn = 1e5;

ll n, d, m;
ll a[MAXn + 5];
vector<ll> b, c;
ll bpsum[2 * MAXn + 5], cpsum[2 * MAXn + 5];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	b.push_back(INF);
	c.push_back(INF);

	cin >> n >> d >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] <= m) b.push_back(a[i]);
		else c.push_back(a[i]);
	}

	sort(b.rbegin(), b.rend());
	sort(c.rbegin(), c.rend());

	for (int i = 1; i < b.size(); i++)
		bpsum[i] = bpsum[i - 1] + b[i];
	for (int i = 1; i < c.size(); i++)
		cpsum[i] = cpsum[i - 1] + c[i];

	ll res = 0;
	for (ll r = 0; d * (r - 1) + r <= n && r < c.size(); r++) {
		//ll l = b.size() - 1 - max(0ll, d * (r - 1));
		ll l = min<ll>(n - r - max<ll>(0, d * (r - 1)), b.size() - 1);
		res = max(res, bpsum[l] + cpsum[r]);
		//cout << r << ' ' << bpsum[l] + cpsum[r] << '\n';
	}

	cout << res;

	return 0;
}