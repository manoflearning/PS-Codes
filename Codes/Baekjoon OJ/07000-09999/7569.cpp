#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int m, n, h;
int box[101][101][101];
bool visited[101][101][101];

int bfs();

int main() {
	cin >> m >> n >> h;

	for (int z = 1; z <= h; z++) {
		for (int y = 1; y <= n; y++) {
			for (int x = 1; x <= m; x++)
				cin >> box[x][y][z];
		}
	}
	
	int ans = bfs();

	bool check = true;
	for (int z = 1; z <= h; z++) {
		for (int y = 1; y <= n; y++) {
			for (int x = 1; x <= m; x++)
				if (!visited[x][y][z] && box[x][y][z] != -1) {
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
		int x;
		int y;
		int z;
		int v;
	};

	queue<b> q;

	for (int z = 1; z <= h; z++) {
		for (int y = 1; y <= n; y++) {
			for (int x = 1; x <= m; x++)
				if (box[x][y][z] == 1) {
					q.push({ x,y,z,0 });
					visited[x][y][z] = true;
				}
		}
	}

	int ret = -1;

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, z = q.front().z, v = q.front().v;

		ret = max(ret, v);

		if (x > 1 && box[x - 1][y][z] != -1 && !visited[x - 1][y][z]) {
			q.push({ x - 1,y,z,v + 1 });
			visited[x - 1][y][z] = true;
		}
		if (x < m && box[x + 1][y][z] != -1 && !visited[x + 1][y][z]) {
			q.push({ x + 1,y,z,v + 1 });
			visited[x + 1][y][z] = true;
		}
		if (y > 1 && box[x][y - 1][z] != -1 && !visited[x][y - 1][z]) {
			q.push({ x,y - 1,z,v + 1 });
			visited[x][y - 1][z] = true;
		}
		if (y < n && box[x][y + 1][z] != -1 && !visited[x][y + 1][z]) {
			q.push({ x,y + 1,z,v + 1 });
			visited[x][y + 1][z] = true;
		}
		if(z > 1 && box[x][y][z - 1] != -1 && !visited[x][y][z - 1]) {
			q.push({ x,y,z - 1,v + 1});
			visited[x][y][z - 1] = true;
		}
		if (z < h && box[x][y][z + 1] != -1 && !visited[x][y][z + 1]) {
			q.push({ x,y,z + 1,v + 1 });
			visited[x][y][z + 1] = true;
		}

		q.pop();
	}

	return ret;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: bfs
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////