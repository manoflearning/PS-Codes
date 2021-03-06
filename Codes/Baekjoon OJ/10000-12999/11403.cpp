#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n;
vector<int> graph[101];
bool visited[101];

bool dfs(int x, int find);

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int l = 1; l <= n; l++) {
			int x;
			cin >> x; 

			if (x == 1) graph[i].push_back(l);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int l = 1; l <= n; l++) {
			memset(visited, 0, sizeof(visited));

			if (dfs(i, l)) cout << 1 << ' ';
			else cout << 0 << ' ';
		}
		cout << '\n'; 
	}

	return 0;
}

bool dfs(int x, int find) {
	visited[x] = true;

	for (int i = 0; i < graph[x].size(); i++) {
		if (find == graph[x][i]) return true;

		if (visited[graph[x][i]]) continue;

		if (dfs(graph[x][i], find)) return true;
	}

	return false;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: dfs
접근 방식		: 시간복잡도 : O(n의 4제곱)
결정적 깨달음		: 
오답 원인		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////