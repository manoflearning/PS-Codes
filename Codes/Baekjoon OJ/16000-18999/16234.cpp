#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int n, l, r;
int graph[50][50];
bool visited[50][50];

vector<pair<int, int>> cpnt;

int dfs(int y, int x);

int main() {
	cin >> n >> l >> r;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> graph[y][x];
		}
	}
	//dfs
	int ans = 0;

	while (true) {
		//reset
		memset(visited, 0, sizeof(visited));

		bool check = false;

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (!visited[y][x]) {
					int div = dfs(y, x);

					if (cpnt.size() > 1) {
						check = true;

						for (int i = 0; i < cpnt.size(); i++)
							graph[cpnt[i].first][cpnt[i].second] = div / cpnt.size();
					}

					cpnt.clear();
				}
			}
		}

		if (check) ans++;
		else break;
	}

	cout << ans;

	return 0;
}

int dfs(int y, int x) {
	visited[y][x] = true;
	cpnt.push_back({ y, x });

	int ret = graph[y][x];

	if (x - 1 >= 0 && !visited[y][x - 1]) {
		int dif = (int)fabs(graph[y][x] - graph[y][x - 1]);
		
		if (l <= dif && dif <= r) ret += dfs(y, x - 1);
	}
	if (x + 1 <= n - 1 && !visited[y][x + 1]) {
		int dif = (int)fabs(graph[y][x] - graph[y][x + 1]);

		if (l <= dif && dif <= r) ret += dfs(y, x + 1);
	}
	if (y - 1 >= 0 && !visited[y - 1][x]) {
		int dif = (int)fabs(graph[y][x] - graph[y - 1][x]);

		if (l <= dif && dif <= r) ret += dfs(y - 1, x);
	}
	if (y + 1 <= n - 1 && !visited[y + 1][x]) {
		int dif = (int)fabs(graph[y][x] - graph[y + 1][x]);

		if (l <= dif && dif <= r) ret += dfs(y + 1, x);
	}

	return ret;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: dfs
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////