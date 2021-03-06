#include <iostream>
#include <queue>
using namespace std;

int m, n;
int box[1001][1001];
bool visited[1001][1001];

int bfs();

int main() {
	cin >> m >> n;

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			cin >> box[y][x];
		}
	}

	int ans = bfs();

	bool check = true;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			if (!visited[y][x] && box[y][x] != -1) {
				check = false;
				break;
			}
		}
	}

	if (check) cout << ans;
	else cout << -1;

	return 0;
}

int bfs() {
	struct b {
		int y;
		int x;
		int v;
	};

	queue<b> q;

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			if (box[y][x] == 1) {
				q.push({ y, x, 0 });
				visited[y][x] = true;
			}
		}
	}

	int ret = -1;

	while (!q.empty()) {
		int y = q.front().y, x = q.front().x, v = q.front().v;
		ret = max(ret, v);

		if (y > 1 && box[y - 1][x] != -1 && !visited[y - 1][x]) {
			visited[y - 1][x] = true;
			q.push({ y - 1, x, v + 1 });
		}
		if (y < n && box[y + 1][x] != -1 && !visited[y + 1][x]) {
			visited[y + 1][x] = true;
			q.push({ y + 1, x, v + 1 });
		}
		if (x > 1 && box[y][x - 1] != -1 && !visited[y][x - 1]) {
			visited[y][x - 1] = true;
			q.push({ y, x - 1, v + 1 });
		}
		if (x < m && box[y][x + 1] != -1 && !visited[y][x + 1]) {
			visited[y][x + 1] = true;
			q.push({ y, x + 1, v + 1 });
		}

		q.pop();
	}

	return ret;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: bfs
접근 방식		: 큐에 1에 해당하는 좌표값을 모두 push하고 시작
결정적 깨달음		: 
오답 원인		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////