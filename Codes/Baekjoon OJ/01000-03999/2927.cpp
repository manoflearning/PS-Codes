#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXV = 3 * 1e4;

struct Query {
	string op, ans;
	int A, B;
}query[300005];

struct uf {
	int p[MAXV + 5];

	int find(int x) {
		if (p[x] < 0) return x;
		return p[x] = find(p[x]);
	}
	void merge(int a, int b) {
		int A = find(a), B = find(b);
		if (A == B) return;
		p[A] += p[B];
		p[B] = A;
	}
}uf;

struct Seg {
	int flag;
	vector<int> t;

	void build(int N) {
		flag = 1;
		while (flag < N) flag *= 2;
		t.resize(2 * flag);
	}
	void modify(int p, int value) {
		for (t[p += flag] = value; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
	}
	int query(int L, int R) {
		return query(L, R, 1, 0, flag - 1);
	}
	int query(int L, int R, int n, int nL, int nR) {
		if (nR < L || R < nL) return 0;
		if (L <= nL && nR <= R) return t[n];

		int mid = (nL + nR) >> 1;
		return query(L, R, 2 * n, nL, mid) + query(L, R, 2 * n + 1, mid + 1, nR);
	}
}seg;

vector<int> adj[MAXV + 5], g[MAXV + 5];
int N, w[MAXV + 5];
bool visited[MAXV + 5];
int sz[MAXV + 5], dep[MAXV + 5], par[MAXV + 5];
int top[MAXV + 5], in[MAXV + 5], out[MAXV + 5], pv = -1;

void init();
void dfs(int v, int prv);
int dfs1(int v);
void dfs2(int v);
int hldQuery(int u, int v);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	init();

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> w[i];

	int Q; cin >> Q;
	for (int i = 0; i < Q; i++) {
		Query& q = query[i];
		cin >> q.op >> q.A >> q.B;

		if (q.op == "bridge") {
			if (uf.find(q.A) != uf.find(q.B)) {
				uf.merge(q.A, q.B);
				q.ans = "yes";
				adj[q.A].push_back(q.B);
				adj[q.B].push_back(q.A);
			}
			else q.ans = "no";
		}
		else if (q.op == "excursion") {
			if (uf.find(q.A) != uf.find(q.B)) q.ans = "impossible";
		}
	}

	seg.build(N);

	for (int v = 1; v <= N; v++) {
		if (visited[v]) continue;
		top[v] = v;
		dfs(v, 0);
		dfs1(v); dfs2(v);
	}

	for (int i = 0; i < Q; i++) {
		Query& q = query[i];

		if (q.op == "bridge") cout << q.ans << '\n';
		else if (q.op == "penguins") {
			w[q.A] = q.B;
			seg.modify(in[q.A], w[q.A]);
		}
		else if (q.op == "excursion") {
			if (q.ans == "impossible") cout << q.ans << '\n';
			else cout << hldQuery(q.A, q.B) << '\n';
		}
	}


	/*cout << seg.t[1] << '\n';
	cout << seg.t[2] << ' ' << seg.t[3] << '\n';
	cout << seg.t[4] << ' ' << seg.t[5] << ' ' << seg.t[6] << ' ' << seg.t[7] << '\n';
	for (int i = seg.flag; i < seg.flag + seg.flag; i++)
		cout << seg.t[i] << ' ';*/

	return 0;
}

void init() {
	memset(uf.p, -1, sizeof(uf.p));
}

void dfs(int v, int prv) {
	visited[v] = true;
	for (int& i : adj[v]) {
		if (i == prv) continue;
		g[v].push_back(i);
		dfs(i, v);
	}
}

int dfs1(int v) {
	sz[v] = 1;
	for (int& i : g[v]) {
		dep[i] = dep[v] + 1, par[i] = v;
		sz[v] += dfs1(i);
		if (sz[i] > sz[g[v][0]]) swap(i, g[v][0]);
	}
	return sz[v];
}

void dfs2(int v) {
	in[v] = ++pv;
	seg.modify(in[v], w[v]);

	for (int& i : g[v]) {
		top[i] = (i == g[v][0] ? top[v] : i);
		dfs2(i);
	}
	out[v] = pv;
}

int hldQuery(int u, int v) {
	int ret = 0;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		int st = top[u];
		ret += seg.query(in[st], in[u]);
		u = par[st];
	}

	if (dep[u] > dep[v]) swap(u, v);
	ret += seg.query(in[u], in[v]);

	return ret;
}