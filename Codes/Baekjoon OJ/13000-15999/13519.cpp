#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXV = 1e5;
const int INF = 1e9 + 7;

struct sgtr {
	int mxL, mxR, mx, all;
};

struct Seg {
	struct Lazy {
		int val;
		bool on;
	};

	int flag;  // array size
	vector<sgtr> t;
	vector<Lazy> lazy;

	void build(int N) {
		for (flag = 1; flag < N; flag <<= 1);
		t.resize(2 * flag);
		lazy.resize(2 * flag);
	}
	void modify(int L, int R, int value) {
		return modify(L, R, 1, 1, flag, value);
	}
	// add a value to all elements in interval [L, R]
	void modify(int L, int R, int n, int nL, int nR, int value) {
		propagate(n, nL, nR);

		if (R < nL || nR < L) return;
		if (L <= nL && nR <= R) {
			lazy[n].val = value, lazy[n].on = true;
			propagate(n, nL, nR);
			return;
		}

		int mid = (nL + nR) / 2;
		modify(L, R, n << 1, nL, mid, value);
		modify(L, R, n << 1 | 1, mid + 1, nR, value);

		t[n] = f(t[n << 1], t[n << 1 | 1]);
	}
	sgtr query(int L, int R) {
		return query(L, R, 1, 1, flag);
	}
	sgtr query(int L, int R, int n, int nL, int nR) {  // sum on interval [L, R]
		propagate(n, nL, nR);

		if (R < nL || nR < L) return { -INF, -INF, -INF, 0 };
		if (L <= nL && nR <= R) return t[n];

		int mid = (nL + nR) >> 1;
		return f(query(L, R, n << 1, nL, mid), query(L, R, n << 1 | 1, mid + 1, nR));
	}
	void propagate(int n, int nL, int nR) {
		if (lazy[n].on) {
			if (n < flag) {
				lazy[n << 1] = lazy[n];
				lazy[n << 1 | 1] = lazy[n];
			}
			t[n].mxL = t[n].mxR = t[n].mx = max(0, lazy[n].val * (nR - nL + 1));
			t[n].all = lazy[n].val * (nR - nL + 1);
			lazy[n].on = false;
		}
	}
	sgtr f(sgtr a, sgtr b) {
		sgtr ret;
		ret.mxL = max(a.all + b.mxL, a.mxL);
		ret.mxR = max(a.mxR + b.all, b.mxR);
		ret.mx = max({ a.mx, b.mx, a.mxR + b.mxL });
		ret.all = a.all + b.all;
		return ret;
	}
}seg;

int N, w[MAXV + 5];
vector<int> adj[MAXV + 5], g[MAXV + 5];
int sz[MAXV + 5], par[MAXV + 5], dep[MAXV + 5];
int top[MAXV + 5], in[MAXV + 5], out[MAXV + 5], pv;

void dfs(int v, int prv);
int dfs1(int v);
void dfs2(int v);
int query(int u, int v);
void modify(int u, int v, int w);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> w[i];
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	seg.build(N);
	dfs(1, 0);
	dfs1(1);
	top[1] = 1;
	dfs2(1);

	int M; cin >> M;
	while (M--) {
		int op, u, v, w;
		cin >> op >> u >> v;
		if (op == 1) cout << query(u, v) << '\n';
		else {
			cin >> w;
			modify(u, v, w);
		}
	}

	//for (int v = 1; v <= N; v++)
	//	cout << seg.query(in[v], in[v]).all << ' ';
	
	return 0;
}

void dfs(int v, int prv) {
	for (auto& i : adj[v]) {
		if (i == prv) continue;
		g[v].push_back(i);
		dfs(i, v);
	}
}

int dfs1(int v) {
	sz[v] = 1;
	for (auto& i : g[v]) {
		par[i] = v, dep[i] = dep[v] + 1;
		sz[v] += dfs1(i);
		if (sz[i] > sz[g[v][0]]) swap(i, g[v][0]);
	}
	return sz[v];
}

void dfs2(int v) {
	in[v] = ++pv;
	seg.modify(in[v], in[v], w[v]);
	for (auto& i : g[v]) {
		top[i] = (i == g[v][0] ? top[v] : i);
		dfs2(i);
	}
	out[v] = pv;
}

int query(int u, int v) {
	vector<sgtr> arr1, arr2;
	
	int uu = u, vv = v;
	while (top[uu] != top[vv]) {
		if (dep[top[uu]] < dep[top[vv]]) swap(uu, vv);
		uu = par[top[uu]];
	}
	if (dep[uu] > dep[vv]) swap(uu, vv);
	int lca = uu;

	while (top[u] != top[lca]) {
		int st = top[u];
		arr1.push_back(seg.query(in[st], in[u]));
		u = par[st];
	}
	arr1.push_back(seg.query(in[lca], in[u]));
	while (top[v] != top[lca]) {
		int st = top[v];
		arr2.push_back(seg.query(in[st], in[v]));
		v = par[st];
	}
	if (v != lca) arr2.push_back(seg.query(in[lca] + 1, in[v]));

	for (int i = 0; i < arr1.size(); i++)
		swap(arr1[i].mxL, arr1[i].mxR);
	for (int i = arr2.size() - 1; i >= 0; i--)
		arr1.push_back(arr2[i]);
	
	int ret = 0;
	for (int st = 0; st < arr1.size(); st++) {
		ret = max(ret, arr1[st].mx);
		
		int sum = arr1[st].mxR;
		for (int en = st + 1; en < arr1.size(); en++) {
			ret = max(ret, sum + arr1[en].mxL);
			sum += arr1[en].all;
		}
	}
	//cout << arr1.size() << '\n';
	//for (int i = 0; i < arr1.size(); i++)
	//	cout << arr1[i].mxL << ' ' << arr1[i].mxR << ' ' << arr1[i].all << '\n';
	return ret;
}

void modify(int u, int v, int w) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		int st = top[u];
		seg.modify(in[st], in[u], w);
		u = par[st];
	}
	if (dep[u] > dep[v]) swap(u, v);
	seg.modify(in[u], in[v], w);
}