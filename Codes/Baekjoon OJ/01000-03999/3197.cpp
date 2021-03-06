#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1500;
const int MV[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1,0} };

struct yx {
	int y; int x;
};
struct yxt {
	int y; int x; int t;
};

int Y, X;
char w[MAX + 5][MAX + 5];
yx p[MAX + 5][MAX + 5];
vector<yx> L;
bool visited[MAX + 5][MAX + 5];

yx find(int y, int x);
void merge(int ay, int ax, int by, int bx);
void dfs(int sy, int sx);
bool isConnected();

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(p, -1, sizeof(p));

	queue<yxt> q;

	cin >> Y >> X;

	for (int y = 1; y <= Y; y++) {
		for (int x = 1; x <= X; x++) {
			cin >> w[y][x];
			if (w[y][x] != 'X') {
				q.push({ y, x, 0 });
				if (w[y][x] == 'L') L.push_back({ y, x });
			}
		}
	}
	//0일차 집합 만들기
	for (int y = 1; y <= Y; y++) {
		for (int x = 1; x <= X; x++) {
			if (w[y][x] != 'X' && !visited[y][x]) dfs(y, x);
		}
	}
	//
	if (isConnected()) {
		cout << 0;
		return 0;
	}
	//얼음 녹이기
	int T = 0, cnt = 0;
	while (!q.empty()) {
		int sy = q.front().y, sx = q.front().x, t = q.front().t;
		q.pop();

		if (t > T) {
			T = t;
			if (isConnected()) {
				cout << t;
				break;
			}
		}

		for (int i = 0; i < 4; i++) {
			int y = sy + MV[i][0], x = sx + MV[i][1];

			if (y < 1 || Y < y || x < 1 || X < x) continue;
			yx A = find(sy, sx), B = find(y, x);
			if (A.y == B.y && A.x == B.x) continue;

			w[y][x] = '.';
			merge(sy, sx, y, x);
			for (int l = 0; l < 4; l++) {
				int yy = y + MV[l][0], xx = x + MV[l][1];
				if (w[yy][xx] == 'X') continue;
				merge(y, x, yy, xx);
			}
			q.push({ y, x, t + 1 });
		}
	}

	return 0;
}

yx find(int y, int x) {
	if (p[y][x].y < 0) return { y, x };
	p[y][x] = find(p[y][x].y, p[y][x].x);
	return p[y][x];
}
void merge(int ay, int ax, int by, int bx) {
	yx A = find(ay, ax), B = find(by, bx);
	if (A.y == B.y && A.x == B.x) return;
	p[A.y][A.x].y = B.y;
	p[A.y][A.x].x = B.x;
}
void dfs(int sy, int sx) {
	visited[sy][sx] = true;
	for (int i = 0; i < 4; i++) {
		int y = sy + MV[i][0], x = sx + MV[i][1];
		if (w[y][x] == 'X') continue;
		if (visited[y][x]) continue;
		if (y < 1 || Y < y || x < 1 || X < x) continue;
		merge(sy, sx, y, x);
		dfs(y, x);
	}
}
bool isConnected() {
	yx A = find(L[0].y, L[0].x), B = find(L[1].y, L[1].x);
	if (!(A.y == B.y && A.x == B.x)) return false;
	return true;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: dfs + bfs + 유니온 파인드
접근 방식		: dfs로 처음부터 집합인 물 묶기, bfs로 얼음 녹이기, 유니온 파인드로 모든 백조가 같은 집합에 포함되어 있는지 확인.
결정적 깨달음		:
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////