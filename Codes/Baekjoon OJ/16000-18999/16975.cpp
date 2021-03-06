#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int flag;
vector<ll> sgtr, lazy;

ll find_sum(int L, int R, int n, int nL, int nR);
void update(int L, int R, int n, int nL, int nR, ll v);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (flag = 1; flag < n; flag *= 2);
	sgtr.resize(2 * flag);
	lazy.resize(2 * flag);

	for (int i = flag; i < flag + n; i++)
		cin >> sgtr[i];
	for (int i = flag - 1; i >= 1; i--)
		sgtr[i] = sgtr[2 * i] + sgtr[2 * i + 1];

	int m;
	cin >> m;

	while (m--) {
		int a, b, c, d;
		cin >> a;

		if (a == 1) {
			cin >> b >> c >> d;
			update(b, c, 1, 1, flag, d);
		}
		else {
			cin >> b;
			cout << find_sum(b, b, 1, 1, flag) << '\n';
		}
	}

	return 0;
}

ll find_sum(int L, int R, int n, int nL, int nR) {
	if (lazy[n]) {
		sgtr[n] += lazy[n] * (nR - nL + 1);
		if (n < flag) {
			lazy[2 * n] += lazy[n];
			lazy[2 * n + 1] += lazy[n];
		}
		lazy[n] = 0;
	}

	if (nR < L || R < nL) return 0;
	if (L <= nL && nR <= R) return sgtr[n];

	int mid = (nL + nR) / 2;
	return find_sum(L, R, 2 * n, nL, mid) + find_sum(L, R, 2 * n + 1, mid + 1, nR);
}
void update(int L, int R, int n, int nL, int nR, ll v) {
	if (lazy[n]) {
		sgtr[n] += lazy[n] * (nR - nL + 1);
		if (n < flag) {
			lazy[2 * n] += lazy[n];
			lazy[2 * n + 1] += lazy[n];
		}
		lazy[n] = 0;
	}

	if (nR < L || R < nL) return;
	if (L <= nL && nR <= R) {
		sgtr[n] += v * (nR - nL + 1);
		if (n < flag) {
			lazy[2 * n] += v;
			lazy[2 * n + 1] += v;
		}
		return;
	}

	int mid = (nL + nR) / 2;
	update(L, R, 2 * n, nL, mid, v);
	update(L, R, 2 * n + 1, mid + 1, nR, v);

	sgtr[n] = sgtr[2 * n] + sgtr[2 * n + 1];
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 세그트리 w 레이지 프로퍼게이션
접근 방식		:
결정적 깨달음		:
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////