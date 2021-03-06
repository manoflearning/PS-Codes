#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXV = 1e5, MAXD = 16;

int N;
vector<int> adj[MAXV + 5];
int depth[MAXV + 5], par[MAXV + 5][MAXD + 5];

void dfs(int now, int prv);
int LCA(int u, int v);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//par 배열 형성
	dfs(1, 0);

	for (int i = 1; i <= MAXD; i++) {
		for (int v = 1; v <= N; v++) {
			par[v][i] = par[par[v][i - 1]][i - 1];
		}
	}

	//
	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		int r, u, v;
		cin >> r >> u >> v;

		int lcaU = LCA(r, u), lcaV = LCA(r, v), lca = LCA(u, v);
		if (depth[lcaU] >= depth[lcaV] && depth[lcaU] >= depth[lca]) cout << lcaU << '\n';
		else if (depth[lcaV] >= depth[lcaU] && depth[lcaV] >= depth[lca]) cout << lcaV << '\n';
		else if (depth[lca] >= depth[lcaU] && depth[lca] >= depth[lcaV]) cout << lca << '\n';
	}

	return 0;
}

void dfs(int now, int prv) {
	for (int next : adj[now]) {
		if (next == prv) continue;
		depth[next] = depth[now] + 1;
		par[next][0] = now;
		dfs(next, now);
	}
}

int LCA(int u, int v) {
	if (depth[u] > depth[v]) swap(u, v);

	//높이 맞추기
	int diff = depth[v] - depth[u];
	for (int i = MAXD; i >= 0; i--) {
		if (diff & (1 << i)) {
			v = par[v][i];
			diff -= (1 << i);
		}
	}

	if (u != v) {
		for (int i = MAXD; i >= 0; i--) {
			if (par[u][i] != par[v][i]) {
				u = par[u][i];
				v = par[v][i];
			}
		}
		u = par[u][0];
		v = par[v][0];
	}

	return u;
}