#include <iostream>
#include <algorithm>
using namespace std;

const int MAXV = 400;
const int INF = 1e9 + 7;

int V, adj[MAXV + 5][MAXV + 5];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < MAXV + 5; i++)
		fill(adj[i], adj[i] + MAXV + 5, INF);

	int E;
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c; 
		cin >> a >> b >> c;
		adj[a][b] = min(adj[a][b], c);
	}

	for (int k = 1; k <= V; k++) {
		for (int u = 1; u <= V; u++) {
			for (int v = 1; v <= V; v++) {
				adj[u][v] = min(adj[u][v], adj[u][k] + adj[k][v]);
			}
		}
	}

	int ans = INF;
	for (int i = 1; i <= V; i++)
		ans = min(ans, adj[i][i]);

	if (ans == INF) cout << -1;
	else cout << ans;

	return 0;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 플로이드 와샬 알고리즘
결정적 깨달음		: adj[i][i] = INF
시간복잡도		: O(|V|^3)
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////