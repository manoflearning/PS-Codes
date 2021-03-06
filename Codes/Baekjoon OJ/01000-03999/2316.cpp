#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 801, PRM = 400;

int N;
vector<int> adj[MAX];
int c[MAX][MAX], f[MAX][MAX], prv[MAX];

void BFS();
void flow();

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int P; cin >> N >> P;

	//유량 그래프 구축
	for (int i = 1; i <= N; i++) {
		adj[i].push_back(i + PRM);
		adj[i + PRM].push_back(i);
		if (i == 1 || i == 2) c[i][i + PRM] = 1e9;
		else c[i][i + PRM] = 1;
	}

	for (int i = 0; i < P; i++) {
		int a, b; cin >> a >> b;
		adj[a + PRM].push_back(b);
		adj[b].push_back(a + PRM);
		adj[b + PRM].push_back(a);
		adj[a].push_back(b + PRM);
		c[b + PRM][a] = c[a + PRM][b] = 1e9;
	}

	//최대 유량 찾기
	int total = 0;

	while (true) {
		BFS();
		
		if (prv[2 + PRM] == -1) break;

		flow();
		total++;
	}

	cout << total;

	return 0;
}

void BFS() {
	memset(prv, -1, sizeof(prv));

	queue<int> q;
	q.push(1);
	prv[1] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int next : adj[now]) {
			if (prv[next] != -1) continue;
			if (c[now][next] - f[now][next] > 0) {
				q.push(next);
				prv[next] = now;
				if (next == 2 + PRM) return;
			}
		}
	}
}

void flow() {
	int n = 2 + PRM;
	while (prv[n] != 0) {
		f[prv[n]][n] += 1;
		f[n][prv[n]] -= 1;
		n = prv[n];
	}
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 네트워크 유량
결정적 깨달음		: 네트워크 유량을 통해 각 정점의 방문 빈도를 제한하고 싶다면, 정점을 둘로 쪼개서 그 두 정점 사이를 있는 간선의 용량을 방문 빈도 제한으로 하면 됨.
시간복잡도		: 
오답 원인		: 1. 역방향 간선이 없었다.
				  2. 
*/////////////////////////////////////////////////////////////////////