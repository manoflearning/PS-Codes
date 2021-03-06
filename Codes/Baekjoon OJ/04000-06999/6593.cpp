#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 30;

struct bb {
	int h;
	int y;
	int x;
	int v;
};

struct cmp {
	bool operator() (bb a, bb b) {
		return a.v > b.v;
	}
};

int l, r, c;
int sh, sy, sx, eh, ey, ex;
char graph[MAX][MAX][MAX];
int sp[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];

void shortestPath();

int main() {
	for (int test = 1; ; test++) {
		//reset
		memset(visited, 0, sizeof(visited));
		//
		cin >> l >> r >> c;

		if (l == 0 && r == 0 && c == 0) break;

		for (int h = 0; h < l; h++) {
			for (int y = 0; y < r; y++) {
				for (int x = 0; x < c; x++) {
					cin >> graph[h][y][x];

					if (graph[h][y][x] == 'S')
						sh = h, sy = y, sx = x;
					if (graph[h][y][x] == 'E')
						eh = h, ey = y, ex = x;
				}
			}
		}
			
		shortestPath();

		if (!visited[eh][ey][ex])
			cout << "Trapped!\n";
		else
			cout << "Escaped in " << sp[eh][ey][ex] << " minute(s).\n";
	}

	return 0;
}

void shortestPath() {
	queue<bb> pq;
	pq.push({ sh, sy, sx, 0 });

	while (!pq.empty()) {
		int h = pq.front().h, y = pq.front().y, x = pq.front().x;
		int v = pq.front().v;

		sp[h][y][x] = v;

		if (h > 0 && graph[h - 1][y][x] != '#' && !visited[h - 1][y][x]) {
			pq.push({ h - 1, y, x, v + 1 });
			visited[h - 1][y][x] = true;
		}
		if (h < l - 1 && graph[h + 1][y][x] != '#' && !visited[h + 1][y][x]) {
			pq.push({ h + 1, y, x, v + 1 });
			visited[h + 1][y][x] = true;
		}
		if (y > 0 && graph[h][y - 1][x] != '#' && !visited[h][y - 1][x]) {
			pq.push({ h, y - 1, x, v + 1 });
			visited[h][y - 1][x] = true;
		}
		if (y < r - 1 && graph[h][y + 1][x] != '#' && !visited[h][y + 1][x]) {
			pq.push({ h, y + 1, x, v + 1 });
			visited[h][y + 1][x] = true;
		}
		if (x > 0 && graph[h][y][x - 1] != '#' && !visited[h][y][x - 1]) {
			pq.push({ h, y, x - 1, v + 1 });
			visited[h][y][x - 1] = true;
		}
		if (x < c - 1 && graph[h][y][x + 1] != '#' && !visited[h][y][x + 1]) {
			pq.push({ h, y, x + 1, v + 1 });
			visited[h][y][x + 1] = true;
		}

		pq.pop();
	}
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: BFS
접근 방식		: 가중치가 없는 최단거리 문제는 BFS로 해결, 3차원 인접행렬.
결정적 깨달음		: 
오답 원인		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////