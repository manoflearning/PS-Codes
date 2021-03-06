#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;

const int MAXV = 1e5;
const int MAXD = 16;

struct dn {
	ll d; int n;
};

int N, f[MAXV + 5][MAXD + 5], depth[MAXV + 5];
ll cost[MAXV + 5][MAXD + 5];
vector<dn> adj[MAXV + 5];

void DFS(int v, int prv, int dep);
int LCA(int u, int v);
int kNode(int st, int k);
ll costCal(int st, int k);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
		adj[v].push_back({ w, u });
	}

	//dfs로 부모 정보 저장
	DFS(1, 0, 1);

	//조상 정보, 비용 정보 저장
	for (int i = 1; i <= MAXD; i++) {
		for (int v = 1; v <= N; v++) {
			f[v][i] = f[f[v][i - 1]][i - 1];
			cost[v][i] = cost[v][i - 1] + cost[f[v][i - 1]][i - 1];
		}
	}

	//쿼리
	int T; cin >> T;

	while (T--) {
		int q, u, v; 
		cin >> q >> u >> v;

		int lca = LCA(u, v);

		if (q == 1) {
			ll ans = costCal(u, depth[u] - depth[lca]);
			ans += costCal(v, depth[v] - depth[lca]);

			cout << ans << '\n';
		}
		else {
			int k; cin >> k;
			k--;
			if (depth[u] - depth[lca] >= k) {
				cout << kNode(u, k) << '\n';
			}
			else {
				k -= (depth[u] - depth[lca]);
				k = (depth[v] - depth[lca]) - k;
				cout << kNode(v, k) << '\n';
			}
		}
	}

	return 0;
}

void DFS(int v, int prv, int dep) {
	depth[v] = dep;

	for (auto next : adj[v]) {
		if (next.n == prv) continue;
		f[next.n][0] = v;
		cost[next.n][0] = next.d;
		DFS(next.n, v, dep + 1);
	}
}

int LCA(int u, int v) {
	if (depth[u] > depth[v]) swap(u, v);

	for (int i = MAXD; i >= 0; i--) {
		if (depth[f[v][i]] >= depth[u]) v = f[v][i];
	}

	if (u == v) return v;

	for (int i = MAXD; i >= 0; i--) {
		if (f[u][i] != f[v][i]) {
			u = f[u][i];
			v = f[v][i];
		}
	}

	return f[u][0];
}

int kNode(int st, int k) {
	for (int i = MAXD; i >= 0; i--) {
		if (k & (1 << i)) st = f[st][i];
	}
	return st;
}

ll costCal(int st, int k) {
	ll ret = 0;
	for (int i = MAXD; i >= 0; i--) {
		if (k & (1 << i)) {
			ret += cost[st][i];
			st = f[st][i];
		}
	}

	return ret;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 희소 배열, lca
결정적 깨달음		: 
시간복잡도		: O(nlgn + mlgm)
오답 원인		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////