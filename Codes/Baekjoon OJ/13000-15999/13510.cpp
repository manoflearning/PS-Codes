#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1e5;

struct Seg {
	int flag;
	vector<int> t;

	void build(int N) {
		for (flag = 1; flag < N; flag <<= 1);
		t.resize(2 * flag);
		for (int i = flag - 1; i >= 1; i--) t[i] = max(t[i << 1], t[i << 1 | 1]);
	}
	void modify(int p, int value) {
		for (t[p += flag] = value; p > 1; p >>= 1) t[p >> 1] = max(t[p], t[p ^ 1]);
	}
	int query(int L, int R) {
		//cout << L << ' ' << R << '\n';
		return query(L, R, 1, 0, flag - 1);
	}
	int query(int L, int R, int n, int nL, int nR) {
		if (R < nL || nR < L) return 0;
		if (L <= nL && nR <= R) {
			//cout << n << ' ' << t[n] << '\n';
			return t[n];
		}
		int mid = (nL + nR) / 2;
		return max(query(L, R, n << 1, nL, mid), query(L, R, n << 1 | 1, mid + 1, nR));
	}
}seg;

struct dv {
	int d, v, label;
};

vector<dv> adj[MAX + 5];
vector<int> g[MAX + 5];
int w[MAX + 5], Hash[MAX + 5];
int sz[MAX + 5], dep[MAX + 5], par[MAX + 5];
int top[MAX + 5], in[MAX + 5], out[MAX + 5], pv = -1;

void dfs(int v, int prv);
int dfs1(int v);
void dfs2(int v);
int query(int u, int v);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	for (int i = 1; i <= N - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v, i });
		adj[v].push_back({ w, u, i });
	}

	seg.build(N);
	w[1] = -1;
	dfs(1, 0);
	dfs1(1); dfs2(1);
	seg.modify(in[1], -1);

	int M; cin >> M;
	while (M--) {
		int q, a, b;
		cin >> q >> a >> b;
		if (q == 1) seg.modify(in[Hash[a]], b);
		else cout << query(a, b) << '\n';
	}

	/*for (int i = 1; i <= seg.flag; i++)
		cout << seg.t[i] << ' ';
	for (int i = seg.flag + 1; i <= seg.flag + N; i++)
		cout << seg.t[i] << ' ';*/

	return 0;
}

void dfs(int v, int prv) {
	for (auto& e : adj[v]) {
		if (e.v == prv) continue;
		g[v].push_back(e.v);
		w[e.v] = e.d;
		Hash[e.label] = e.v;
		dfs(e.v, v);
	}
}

int dfs1(int v) {
	sz[v] = 1;
	for (auto& i : g[v]) {
		dep[i] = dep[v] + 1; par[i] = v;
		sz[v] += dfs1(i);
		if (sz[i] > sz[g[v][0]]) swap(i, g[v][0]);
	}
	return sz[v];
}

void dfs2(int v) {
	in[v] = ++pv;
	seg.modify(in[v], w[v]);
	for (auto& i : g[v]) {
		top[i] = (i == g[v][0] ? top[v] : i);
		dfs2(i);
	}
	out[v] = pv;
}

int query(int u, int v) {
	int ret = -1;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		int st = top[u];
		ret = max(ret, seg.query(in[st], in[u]));
		u = par[st];
	}
	if (dep[u] > dep[v]) swap(u, v);
	ret = max(ret, seg.query(in[g[u][0]], in[v]));
	return ret;
}