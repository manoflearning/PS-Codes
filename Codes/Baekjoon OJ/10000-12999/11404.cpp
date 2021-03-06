#include <iostream>
#include <algorithm>
using namespace std;

const int MAXV = 100;
const int INF = 1e9 + 7;

int N, M, adj[MAXV + 5][MAXV + 5];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//초기화
	for (int i = 0; i < MAXV + 5; i++)
		fill(adj[i], adj[i] + MAXV + 5, INF);
	//
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		if (adj[a][b] == 0) adj[a][b] = c;
		else adj[a][b] = min(adj[a][b], c);
	}
	
	for (int i = 0; i < N; i++) adj[i][i] = 0;

	for (int k = 0; k < N; k++) {
		for (int u = 0; u < N; u++) {
			for (int v = 0; v < N; v++) {
				adj[u][v] = min(adj[u][v], adj[u][k] + adj[k][v]);
			}
		}
	}

	for (int u = 0; u < N; u++) {
		for (int v = 0; v < N; v++) {
			if (adj[u][v] < INF) cout << adj[u][v] << ' ';
			else cout << 0 << ' ';
		}
		cout << '\n';
	}

	return 0;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 플로이드 와샬 알고리즘
결정적 깨달음		: 
시간복잡도		: O(|V|^3)
오답 원인		: 1. 경로가 없는 두 정점 쌍을 고려하지 못함
				  2. 
*/////////////////////////////////////////////////////////////////////