#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

const int INF = 1e9 + 7;

struct sgtr {
	//mx는 구간의 연속합 최댓값, all은 구간합
	//mxL을 nL을 포함하는 구간의 연속합 최댓값
	//mxR은 nR을 포함하는 구간의 연속합 최댓값
	ll mx, mxL, mxR, all;
};

int flag;
vector<sgtr> t;

sgtr query(int L, int R, int n, int nL, int nR);
sgtr f(sgtr left, sgtr right);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;

	for (flag = 1; flag < N; flag *= 2);
	t.resize(2 * flag);

	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		t[flag + i].mx = t[flag + i].mxL = t[flag + i].mxR = t[flag + i].all = x;
	}

	for (int i = flag - 1; i >= 1; i--) {
		t[i] = f(t[i << 1], t[i << 1 | 1]);
	}

	int M; cin >> M;
	while (M--) {
		int L, R;
		cin >> L >> R;
		
		cout << query(L, R, 1, 1, flag).mx << '\n';
	}

	return 0;
}

sgtr query(int L, int R, int n, int nL, int nR) {
	if (R < nL || nR < L) return { -INF, -INF, -INF };
	if (L <= nL && nR <= R) return t[n];
	
	int mid = (nL + nR) >> 1;
	return f(query(L, R, 2 * n, nL, mid), query(L, R, 2 * n + 1, mid + 1, nR));
}

sgtr f(sgtr left, sgtr right) {
	sgtr ret;
	ret.mxL = max(left.mxL, left.all + right.mxL);
	ret.mxR = max(right.mxR, left.mxR + right.all);
	ret.mx = max({ left.mx, right.mx, left.mxR + right.mxL });
	ret.all = left.all + right.all;
	return ret;
}