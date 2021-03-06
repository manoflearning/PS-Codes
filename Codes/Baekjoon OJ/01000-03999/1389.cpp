#include <iostream>
#include <algorithm>
using namespace std;

const int MAXV = 100;
const int INF = 1e9 + 7;

int adj[MAXV + 5][MAXV + 5];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < MAXV + 5; i++)
		fill(adj[i], adj[i] + MAXV + 5, INF);

	int N, M; cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		adj[a][b] = adj[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) adj[i][i] = 0;

	for (int k = 1; k <= N; k++) {
		for (int u = 1; u <= N; u++) {
			for (int v = 1; v <= N; v++) {
				adj[u][v] = min(adj[u][v], adj[u][k] + adj[k][v]);
			}
		}
	}

	int ans, flag = INF;

	for (int u = 1; u <= N; u++) {
		int sum = 0;
		for (int v = 1; v <= N; v++) {
			sum += adj[u][v];
		}

		if (sum < flag) {
			flag = sum;
			ans = u;
		}
	}

	cout << ans;

	return 0;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 플로이드 와샬 알고리즘
결정적 깨달음		: 
시간복잡도		: 
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////