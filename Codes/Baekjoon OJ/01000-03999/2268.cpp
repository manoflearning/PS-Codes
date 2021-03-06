#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int flag;
vector<long long> sgtr;

long long sum(int L, int R, int n, int nL, int nR);
void update(int num, int value);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (flag = 1; flag < n; flag *= 2);
	sgtr.resize(2 * flag);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0) {
			if (b > c) swap(b, c);
			cout << sum(b, c, 1, 1, flag) << '\n';
		}
		else update(b, c);
	}

	return 0;
}

long long sum(int L, int R, int n, int nL, int nR) {
	if (R < nL || nR < L) return 0;
	if (L <= nL && nR <= R) return sgtr[n];

	int mid = (nL + nR) / 2;
	return sum(L, R, 2 * n, nL, mid) + sum(L, R, 2 * n + 1, mid + 1, nR);
}
void update(int num, int value) {
	int upd = (flag - 1) + num;
	sgtr[upd] = value;

	while (upd > 1) {
		upd /= 2;

		sgtr[upd] = sgtr[2 * upd] + sgtr[2 * upd + 1];
	}
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 세그먼트 트리
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 빠른 입출력이 아님
				  2. 
*/////////////////////////////////////////////////////////////////////