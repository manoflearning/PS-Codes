#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

const int MAX = 800;

vector<pair<int, int>> graph[MAX + 1];

int shortestPath(int start, int end);

int main() {
	int n, e;
	cin >> n >> e;
	//make graph
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back({ c, b });
		graph[b].push_back({ c, a });
	}
	//
	int vi1, vi2;
	cin >> vi1 >> vi2;
	//
	long long oneTovi1 = shortestPath(1, vi1), oneTovi2 = shortestPath(1, vi2);
	long long vi1Tovi2 = shortestPath(vi1, vi2);
	long long vi1ToN = shortestPath(vi1, n), vi2ToN = shortestPath(vi2, n);

	long long ans = min(oneTovi1 + vi1Tovi2 + vi2ToN, oneTovi2 + vi1Tovi2 + vi1ToN);

	if (ans < INT_MAX) cout << ans;
	else cout << -1;

	return 0;
}

int shortestPath(int start, int end) {
	int sp[MAX + 1];
	for (int i = 1; i <= MAX; i++)
		sp[i] = INT_MAX;
	//
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int n = pq.top().second, v = pq.top().first;

		if (n == end) {
			sp[n] = v;
			break;
		}

		if (v < sp[n]) {
			sp[n] = v;

			for (int i = 0; i < graph[n].size(); i++)
				pq.push({ v + graph[n][i].first, graph[n][i].second });
		}

		pq.pop();
	}

	return sp[end];
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 다익스트라 알고리즘의 응용
접근 방식		: 정점 a에서, 두 정점을 거친 후, 정점 b로 이동하는 최단거리를 구하는 문제. 문제를 부분 문제로 나누어서 풀음.
결정적 깨달음		: 
오답 원인		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////