#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int flag;  // array size
vector<ll> t;

void modify(int p, int value);
ll query(int L, int R, int n, int nL, int nR);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, Q; 
	cin >> N >> Q;

	for (flag = 1; flag < N; flag <<= 1);
	t.resize(2 * flag);

	for (int i = 0; i < N; i++) cin >> t[flag + i];
	for (int i = flag - 1; i >= 1; i--) t[i] = t[i << 1] + t[i << 1 | 1];

	while (Q--) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;

		if (x > y) swap(x, y);

		cout << query(x - 1, y - 1, 1, 0, flag - 1) << '\n';
		modify(a - 1, b);
	}

	return 0;
}

void modify(int p, int value) {  // set value at position p
	for (t[p += flag] = value; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
}

ll query(int L, int R, int n, int nL, int nR) {  // sum on interval [L, R]
	if (R < nL || nR < L) return 0;
	if (L <= nL && nR <= R) return t[n];

	int mid = (nL + nR) / 2;
	return query(L, R, n << 1, nL, mid) + query(L, R, n << 1 | 1, mid + 1, nR);
}