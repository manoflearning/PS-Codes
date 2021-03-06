#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	vector<ll> a(N);
	for (ll& i : a) cin >> i;

	ll yen = 1000, stock = 0;
	for (int i = 0; i < a.size(); i++) {
		if (i < a.size() - 1 && a[i] < a[i + 1]) {
			stock +=  yen / a[i];
			yen %= a[i];
		}
		if (i < a.size() - 1 && a[i] > a[i + 1]) {
			yen += a[i] * stock;
			stock = 0;
		}
	}

	if (stock) yen += a.back() * stock;

	cout << yen;

	return 0;
}
