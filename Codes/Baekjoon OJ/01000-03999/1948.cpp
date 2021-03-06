#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXV = 1e4;

struct dn {
	int d, n;
};
struct cmp {
	bool operator() (dn a, dn b) {
		return a.d < b.d;
	}
};

int N, st, en, dist[MAXV + 5];
vector<dn> adj[MAXV + 5], rev_adj[MAXV + 5];
bool visited[MAXV + 5];

void find_max();
int dfs(int v);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		adj[u].push_back({ d, v });
		rev_adj[v].push_back({ d, u });
	}

	cin >> st >> en;

	//다익스트라
	find_max();

	//dfs
	int cnt = dfs(en);

	cout << dist[en] << '\n';
	cout << cnt;

	return 0;
}

void find_max() {
	memset(dist, -1, sizeof(dist));

	priority_queue<dn, vector<dn>, cmp> pq;
	pq.push({ 0, st });

	dist[st] = 0;

	while (!pq.empty()) {
		int d = pq.top().d, n = pq.top().n;
		pq.pop();

		if (d < dist[n]) continue;

		for (auto next : adj[n]) {
			if (dist[next.n] < d + next.d) {
				dist[next.n] = d + next.d;
				pq.push({ d + next.d, next.n });
			}
		}
	}
}
int dfs(int v) {
	int ret = 0;
	visited[v] = true;
	for (auto prv : rev_adj[v]) {
		if (dist[prv.n] + prv.d == dist[v]) {
			if (!visited[prv.n]) ret += dfs(prv.n) + 1;
			else ret += 1;
		}
	}
	return ret;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 다익스트라, 최단거리 역추적
결정적 깨달음		: 최단거리 역추적은 역방향 그래프를 그려서 최단거리 배열의 값과의 비교를 통해 할 수 있다.
시간복잡도		: O(|E|lg|E|)
오답 원인		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////