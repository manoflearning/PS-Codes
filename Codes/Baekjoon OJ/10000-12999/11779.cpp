#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 1e3;
const int INF = 1e9 + 7;

struct dn {
	int d, n;
};
struct cmp {
	bool operator() (dn a, dn b) {
		return a.d > b.d;
	}
};

int N, st, en, dist[MAX + 5], prv[MAX + 5];
vector<dn> adj[MAX + 5];

void find_min();
void print(int v);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	fill(dist, dist + MAX + 5, INF);
	fill(prv, prv + MAX + 5, -1);

	int M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c; 
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
	}

	cin >> st >> en;

	find_min();

	int cost = dist[en], cnt = 1;

	int v = en;
	while (prv[v] != -1) {
		v = prv[v];
		cnt++;
	}

	cout << cost << '\n' << cnt << '\n';
	print(en);

	return 0;
}

void find_min() {
	priority_queue<dn, vector<dn>, cmp> pq;
	pq.push({ 0, st });
	dist[st] = 0;

	while (!pq.empty()) {
		int d = pq.top().d, n = pq.top().n;
		pq.pop();

		if (dist[n] < d) continue;

		if (n == en) return;

		for (dn next : adj[n]) {
			if (dist[next.n] > d + next.d) {
				prv[next.n] = n;
				dist[next.n] = d + next.d;
				pq.push({ d + next.d, next.n });
			}
		}
	}
}
void print(int v) {
	if (prv[v] != -1) print(prv[v]);
	cout << v << ' ';
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 다익스트라 알고리즘, 최단거리 역추적
결정적 깨달음		: 
시간복잡도		: O(|E|lg|E|)
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////