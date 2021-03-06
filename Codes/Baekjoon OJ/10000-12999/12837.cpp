#include <iostream>
#include <vector>
using namespace std;

int flag;
vector<long long> sgtr;

void update(int num, int value);
long long sum(int L, int R, int n, int nL, int nR);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;

	for (flag = 1; flag < n; flag *= 2);
	sgtr.resize(2 * flag);

	for (int i = 0; i < q; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1) update(b, c);
		else cout << sum(b, c, 1, 1, flag) << '\n';
	}

	return 0;
}

void update(int num, int value) {
	int upd = (flag - 1) + num;
	sgtr[upd] += value;

	while (upd > 1) {
		upd /= 2;

		sgtr[upd] = sgtr[2 * upd] + sgtr[2 * upd + 1];
	}
}

long long sum(int L, int R, int n, int nL, int nR) {
	if (R < nL || nR < L) return 0;
	if (L <= nL && nR <= R) return sgtr[n];

	int mid = (nL + nR) / 2;
	return sum(L, R, 2 * n, nL, mid) + sum(L, R, 2 * n + 1, mid + 1, nR);
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 세그먼트 트리 (구간 트리)
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 아무런 처리 없는 cin, cout은 매우 느림
				  2. 
*/////////////////////////////////////////////////////////////////////