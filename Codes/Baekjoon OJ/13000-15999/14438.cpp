#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int flag;
vector<int> sgtr;

void update(int num, int value);
int MIN(int L, int R, int n, int nL, int nR);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (flag = 1; flag < n; flag *= 2);
	sgtr.resize(2 * flag, INT_MAX);
	//construct
	for (int i = flag; i < flag + n; i++)
		cin >> sgtr[i];

	for (int i = flag - 1; i >= 1; i--)
		sgtr[i] = min(sgtr[2 * i], sgtr[2 * i + 1]);
	//
	int q;
	cin >> q;

	for (int i = 0; i < q; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1) update(b, c);
		else cout << MIN(b, c, 1, 1, flag) << '\n';
	}

	return 0;
}

void update(int num, int value) {
	int upd = (flag - 1) + num;
	sgtr[upd] = value;

	while (upd > 1) {
		upd /= 2;

		sgtr[upd] = min(sgtr[2 * upd], sgtr[2 * upd + 1]);
	}
}
int MIN(int L, int R, int n, int nL, int nR) {
	if (R < nL || nR < L) return INT_MAX;
	if (L <= nL && nR <= R) return sgtr[n];

	int mid = (nL + nR) / 2;
	return min(MIN(L, R, 2 * n, nL, mid), MIN(L, R, 2 * n + 1, mid + 1, nR));
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 세그먼트 트리
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 입출력 시간
				  2. 
*/////////////////////////////////////////////////////////////////////