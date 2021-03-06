#include <iostream>
#include <cstring>
using namespace std;

const int MOV[8][2] = { {1,0},{0,1},{-1,0}, {0, -1},{1,1},{1,-1},{-1,1},{-1,-1} };

int w, h;
bool graph[51][51];
bool visited[51][51];

void dfs(int y, int x);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		memset(visited, 0, sizeof(visited));

		cin >> w >> h;

		if (w == 0 && h == 0) break;

		for (int y = 1; y <= h; y++) {
			for (int x = 1; x <= w; x++) {
				cin >> graph[y][x];
			}
		}
		//
		int ans = 0;
		for (int y = 1; y <= h; y++) {
			for (int x = 1; x <= w; x++) {
				if (graph[y][x] && !visited[y][x]) {
					dfs(y, x);
					ans++;
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}

void dfs(int y, int x) {
	for (int i = 0; i < 8; i++) {
		int Y = y + MOV[i][0], X = x + MOV[i][1];
		if (Y < 1 || h < Y || X < 1 || w < X) continue;
		if (visited[Y][X]) continue;
		if (!graph[Y][X]) continue;
		visited[Y][X] = true;
		dfs(Y, X);
	}
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: dfs
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////