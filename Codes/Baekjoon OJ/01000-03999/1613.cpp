#include <iostream>
#include <algorithm>
using namespace std;

const int MAXV = 400;
const int INF = 1e9 + 7;

int past[MAXV + 5][MAXV + 5], future[MAXV + 5][MAXV + 5];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < MAXV + 5; i++) {
		fill(past[i], past[i] + MAXV + 5, INF);
		fill(future[i], future[i] + MAXV + 5, INF);
	}

	int N, M; cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		future[a][b] = 1;
		past[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		future[i][i] = past[i][i] = 0;
	}

	for (int k = 1; k <= N; k++) {
		for (int u = 1; u <= N; u++) {
			for (int v = 1; v <= N; v++) {
				future[u][v] = min(future[u][v], future[u][k] + future[k][v]);
				past[u][v] = min(past[u][v], past[u][k] + past[k][v]);
			}
		}
	}

	int T; cin >> T;

	while (T--) {
		int a, b; cin >> a >> b;
		if (0 < future[a][b] && future[a][b] < INF) cout << "-1\n";
		else if (0 < past[a][b] && past[a][b] < INF) cout << "1\n";
		else cout << "0\n";
	}

	return 0;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 플로이드 와샬 알고리즘.
결정적 깨달음		: 2개의 플로이드 와샬 알고리즘을 운용하여, 각각 전 관계와 후 관계를 판별함
시간복잡도		: 
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////