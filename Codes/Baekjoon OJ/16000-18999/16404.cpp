#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000;

int N, M;
int siz[MAX + 1], num[MAX + 1], nm = 1;
vector<int> tree[MAX + 1], sgtr, lazy;
int flag;

void dfs(int node, int last);
void update(int L, int R, int n, int nL, int nR, int v);
int print(int L, int R, int n, int nL, int nR);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int x; cin >> x;
		if (x == -1) continue;
		tree[x].push_back(i);
		tree[i].push_back(x);
	}

	for (flag = 1; flag < N; flag *= 2);
	sgtr.resize(2 * flag);
	lazy.resize(2 * flag);

	dfs(1, 0);

	while (M--) {
		int a, b, c;
		cin >> a;

		if (a == 1) {
			cin >> b >> c;
			update(num[b], num[b] + siz[b] - 1, 1, 1, flag, c);
		}
		else {
			cin >> b;
			cout << print(num[b], num[b], 1, 1, flag) << '\n';
		}
	}

	return 0;
}

void dfs(int node, int last) {
	num[node] = nm, nm++;
	siz[node] = 1;

	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i] == last) continue;
		dfs(tree[node][i], node);
		siz[node] += siz[tree[node][i]];
	}
}
void update(int L, int R, int n, int nL, int nR, int v) {
	if (lazy[n] != 0) {
		sgtr[n] += lazy[n] * (nR - nL + 1);
		if (n < flag) {
			lazy[2 * n] += lazy[n];
			lazy[2 * n + 1] += lazy[n];
		}
		lazy[n] = 0;
	}

	if (R < nL || nR < L) return;
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
int print(int L, int R, int n, int nL, int nR) {
	if (lazy[n] != 0) {
		sgtr[n] += lazy[n] * (nR - nL + 1);
		if (n < flag) {
			lazy[2 * n] += lazy[n];
			lazy[2 * n + 1] += lazy[n];
		}
		lazy[n] = 0;
	}

	if (R < nL || nR < L) return 0;
	if (L <= nL && nR <= R) return sgtr[n];

	int mid = (nL + nR) / 2;
	return print(L, R, 2 * n, nL, mid) + print(L, R, 2 * n + 1, mid + 1, nR);
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 세그트리, 레이지 프로퍼게이션
접근 방식		: 
결정적 깨달음		: 트리를 순회를 통해 일렬로 나열할 수 있다.
오답 원인		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////