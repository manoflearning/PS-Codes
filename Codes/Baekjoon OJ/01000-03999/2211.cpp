#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1001;

int n, m, prv[MAX];
vector<pair<int, int>> graph[MAX];
vector<int> dist(MAX, 10 * 1000 + 1);

void shortestpath();

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;


	for (int i = 0; i < m; i++) {
		int n1, n2, v;
		cin >> n1 >> n2 >> v;
		graph[n1].push_back({ v, n2 });
		graph[n2].push_back({ v, n1 });
	}

	//다익스트라
	shortestpath();

	//답 출력
	cout << n - 1 << '\n';
	for (int i = 2; i <= n; i++) {
		if (prv[i] == 0) continue;
		cout << i << ' ' << prv[i] << '\n';
	}

	return 0;
}

void shortestpath() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[1] = 0;
	pq.push({ dist[1], 1 });

	while (!pq.empty()) {
		int v = pq.top().first, n = pq.top().second;
		pq.pop();

		for (pair<int, int> next : graph[n]) {
			if (dist[next.second] > dist[n] + next.first) {
				dist[next.second] = dist[n] + next.first;
				pq.push({ dist[next.second], next.second });
				prv[next.second] = n;
			}
		}
	}
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 다익스트라 알고리즘 + prev 배열
결정적 깨달음		: 
시간복잡도		: O(mlgn)
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////