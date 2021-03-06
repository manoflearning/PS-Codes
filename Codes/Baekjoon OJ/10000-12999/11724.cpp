#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> graph[1001];
bool visited[1001];

void dfs(int x);

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			ans++;
		}
	}

	cout << ans;

	return 0;
}

void dfs(int x) {
	visited[x] = true;

	for (int i = 0; i < graph[x].size(); i++) {
		if (visited[graph[x][i]]) continue;
		
		dfs(graph[x][i]);
	}
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: dfs
접근 방식		: dfs로 방문 노드를 저장.
결정적 깨달음		: 
오답 원인		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////