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

struct Seg {
	int flag;  // array size
	vector<ll> t, lazy;

	void build(int N) {
		for (flag = 1; flag < N; flag <<= 1);
		t.resize(2 * flag);
		lazy.resize(2 * flag);

		for (int i = flag; i < flag + N; i++) cin >> t[i];
		for (int i = flag - 1; i >= 1; i--) t[i] = t[i << 1] ^ t[i << 1 | 1];
	}
	void modify(int l, int r, int value) {
		return modify(l, r, 1, 1, flag, value);
	}
	// add a value to all elements in interval [l, r]
	void modify(int l, int r, int n, int nl, int nr, int value) {
		propagate(n, nl, nr);

		if (r < nl || nr < l) return;
		if (l <= nl && nr <= r) {
			lazy[n] ^= value;
			propagate(n, nl, nr);
			return;
		}

		int mid = (nl + nr) >> 1;
		modify(l, r, n << 1, nl, mid, value);
		modify(l, r, n << 1 | 1, mid + 1, nr, value);

		t[n] = t[n << 1] ^ t[n << 1 | 1];
	}
	ll query(int l, int r) {
		return query(l, r, 1, 1, flag);
	}
	ll query(int l, int r, int n, int nl, int nr) {  // sum on interval [l, r]
		propagate(n, nl, nr);

		if (r < nl || nr < l) return 0;
		if (l <= nl && nr <= r) return t[n];

		int mid = (nl + nr) / 2;
		return query(l, r, n << 1, nl, mid) ^ query(l, r, n << 1 | 1, mid + 1, nr);
	}
	void propagate(int n, int nl, int nr) {
		if (lazy[n] != 0) {
			if (n < flag) {
				lazy[n << 1] ^= lazy[n];
				lazy[n << 1 | 1] ^= lazy[n];
			}
			if ((nr - nl + 1) & 1) t[n] ^= lazy[n];
			lazy[n] = 0;
		}
	}
}seg;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n;
	seg.build(n);

	cin >> m;
	while (m--) {
		int q, a, b, c;
		cin >> q >> a >> b;
		if (q == 1) {
			cin >> c;
			seg.modify(a + 1, b + 1, c);
		}
		else {
			cout << seg.query(a + 1, b + 1) << '\n';
		}
	}

    return 0;
}