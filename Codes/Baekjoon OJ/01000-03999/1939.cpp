#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXV = 1e4;
const int INF = 1e9 + 7;

struct dn {
	int d, n;
};
struct cmp {
	bool operator() (dn a, dn b) {
		return a.d < b.d;
	}
};

int N, st, en, dist[MAXV + 5];
vector<dn> adj[MAXV + 5];

void find_min();

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}

	cin >> st >> en;

	//다익스트라
	find_min();

	cout << dist[en];

	return 0;
}

void find_min() {
	priority_queue<dn, vector<dn>, cmp> pq;
	pq.push({ INF, st });

	dist[st] = INF;

	while (!pq.empty()) {
		int d = pq.top().d, n = pq.top().n;
		pq.pop();

		if (d < dist[n]) continue;
		if (n == en) break;

		for (auto next : adj[n]) {
			if (dist[next.n] < min(d, next.d)) {
				dist[next.n] = min(d, next.d);
				pq.push({ dist[next.n], next.n });
			}
		}
	}
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 다익스트라 알고리즘의 응용
결정적 깨달음		:
시간복잡도		: O(|E|lg|E|)
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////