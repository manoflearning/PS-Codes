#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 1e4;
const int INF = 1e9 + 7;

struct dn {
	int d, n;
};
struct cmp {
	bool operator() (dn a, dn b) {
		return a.d > b.d;
	}
};

int N, cnt, dist[MAX + 5];
vector<dn> adj[MAX + 5];

int find_min(int st);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;

	while (T--) {
		for (int i = 0; i < MAX + 5; i++)
			adj[i].clear();
		cnt = 0;
		//테스트케이스 시작
		int M, st;
		cin >> N >> M >> st;

		for (int i = 0; i < M; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			adj[b].push_back({ c,a });
		}

		int ans = find_min(st);

		cout << cnt << ' ' << ans << '\n';
	}

	return 0;
}

int find_min(int st) {
	fill(dist, dist + MAX + 5, INF);

	priority_queue<dn, vector<dn>, cmp> pq;
	pq.push({ 0, st });
	dist[st] = 0;

	int ret = 0;

	while (!pq.empty()) {
		int d = pq.top().d, n = pq.top().n;
		pq.pop();

		if (dist[n] < d) continue;

		ret = max(ret, d);
		cnt++;

		for (dn next : adj[n]) {
			if (dist[next.n] > next.d + d) {
				dist[next.n] = next.d + d;
				pq.push({ dist[next.n], next.n });
			}
		}
	}

	return ret;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 다익스트라의 단일 시작점 최단 경로 알고리즘
결정적 깨달음		: 
시간복잡도		: O(|E|lg|V|)
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////