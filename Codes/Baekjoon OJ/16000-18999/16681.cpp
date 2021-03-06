#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;

const int MAX = 100001;
const ll MAXD = (ll)100000 * 200000 + 1;

int N, M, D, E;
ll h[MAX], distS[MAX], distE[MAX];
vector<pair<ll, int>> adj[MAX];

void shortest_S();
void shortest_E();

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 1; i < MAX; i++)
		distS[i] = distE[i] = MAXD;

	cin >> N >> M >> D >> E;

	for (int i = 1; i <= N; i++)
		cin >> h[i];

	for (int i = 0; i < M; i++) {
		int n1, n2, d;
		cin >> n1 >> n2 >> d;
		adj[n1].push_back({ d,n2 });
		adj[n2].push_back({ d,n1 });
	}

	shortest_S();
	shortest_E();

	ll ans = -((ll)100 * MAXD);
	for (int i = 2; i <= N - 1; i++) {
		if (distS[i] == MAXD || distE[i] == MAXD) continue;
		ans = max(ans, E * h[i] - D * (distS[i] + distE[i]));
	}

	if (ans == -((ll)100 * MAXD)) cout << "Impossible";
	else cout << ans;

	return 0;
}

void shortest_S() {
	priority_queue<pair<ll, int>> pq;
	pq.push({ 0, 1 });
	distS[1] = 0;

	while (!pq.empty()) {
		ll d = pq.top().first, now = pq.top().second;
		pq.pop();

		for (pair<ll, int> next : adj[now]) {
			if (h[next.second] <= h[now]) continue;
			if (distS[next.second] <= d + next.first) continue;
			
			distS[next.second] = d + next.first;
			pq.push({ d + next.first, next.second });
		}
	}
}
void shortest_E() {
	priority_queue<pair<ll, int>> pq;
	pq.push({ 0, N });
	distE[N] = 0;

	while (!pq.empty()) {
		ll d = pq.top().first, now = pq.top().second;
		pq.pop();

		for (pair<ll, int> next : adj[now]) {
			if (h[next.second] <= h[now]) continue;
			if (distE[next.second] <= d + next.first) continue;

			distE[next.second] = d + next.first;
			pq.push({ d + next.first, next.second });
		}
	}
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 다익스트라 알고리즘
결정적 깨달음		: 시작점과 끝점을 기준으로 각각 다익스트라를 취해줌
시간복잡도		: O(ElgV)
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////