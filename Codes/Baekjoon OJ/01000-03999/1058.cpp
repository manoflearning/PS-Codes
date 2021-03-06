#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct dn {
	int d, n;
};

int N;
vector<int> adj[55];
bool visited[55];

int bfs(int st);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			char a; cin >> a;
			if (a == 'Y') adj[y].push_back(x);
		}
	}

	int ans = 0;
	for (int v = 1; v <= N; v++) {
		ans = max(ans, bfs(v));
	}

	cout << ans;

	return 0;
}

int bfs(int st) {
	memset(visited, 0, sizeof(visited));

	queue<dn> q;
	q.push({ 0, st });
	visited[st] = true;

	int ret = 0;

	while (!q.empty()) {
		int d = q.front().d, n = q.front().n;
		q.pop();

		ret++;

		for (int next : adj[n]) {
			if (visited[next]) continue;
			visited[next] = true;
			if(d < 2) q.push({ d + 1, next });
		}
	}

	return ret - 1;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: bfs
결정적 깨달음		: 가중치가 없는 최단거리 문제는 bfs로 풀 수 있다.
시간복잡도		: O(|V|*(|V| + |E|))
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////