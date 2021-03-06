#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 50;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

struct yxr {
	int y, x;
	bool row;
};

int N;
yxr st, en;
char arr[MAX + 5][MAX + 5];
int dist[MAX + 5][MAX + 5][2];

void scan();
int bfs();
bool canChng(int y, int x);
bool canGo(int y, int x, bool row);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	scan();

	int ans = bfs();
	cout << ans << '\n';

	return 0;
}

void scan() {
	cin >> N;

	int Bcnt = 0, Ecnt = 0;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> arr[y][x];

			if (arr[y][x] == 'B') {
				Bcnt++;
				if (Bcnt == 2) {
					st.y = y, st.x = x;
					if (arr[y - 1][x] == 'B') st.row = false;
					else st.row = true;
				}
			}
			if (arr[y][x] == 'E') {
				Ecnt++;
				if (Ecnt == 2) {
					en.y = y, en.x = x;
					if (arr[y - 1][x] == 'E') en.row = false;
					else en.row = true;
				}
			}
		}
	}
}

int bfs() {
	memset(dist, -1, sizeof(dist));

	queue<yxr> q;
	q.push(st);
	dist[st.y][st.x][st.row] = 0;

	int& ret = dist[en.y][en.x][en.row];

	while (!q.empty() && ret == -1) {
		int y = q.front().y, x = q.front().x;
		bool row = q.front().row;
		q.pop();

		//T
		if (dist[y][x][!row] == -1 && canChng(y, x)) {
			dist[y][x][!row] = dist[y][x][row] + 1;
			q.push({ y, x, !row });
		}

		//U, D, L, R
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < 1 || N < ny || nx < 1 || N < nx) continue;

			if (dist[ny][nx][row] == -1 && canGo(ny, nx, row)) {
				dist[ny][nx][row] = dist[y][x][row] + 1;
				q.push({ ny, nx, row });
			}
		}
	}

	return ret != -1 ? ret : 0;
}

bool canChng(int y, int x) {
	if (y == 1 || y == N || x == 1 || x == N) return false;

	if (arr[y - 1][x - 1] == '1') return false;
	if (arr[y - 1][x] == '1') return false;
	if (arr[y - 1][x + 1] == '1') return false;
	if (arr[y][x - 1] == '1') return false;
	if (arr[y][x + 1] == '1') return false;
	if (arr[y + 1][x - 1] == '1') return false;
	if (arr[y + 1][x] == '1') return false;
	if (arr[y + 1][x + 1] == '1') return false;

	return true;
}

bool canGo(int y, int x, bool row) {
	if (row) {
		if (x == 1 || x == N) return false;

		if (arr[y][x - 1] == '1') return false;
		if (arr[y][x] == '1') return false;
		if (arr[y][x + 1] == '1') return false;
	}
	else {
		if (y == 1 || y == N) return false;

		if (arr[y - 1][x] == '1') return false;
		if (arr[y][x] == '1') return false;
		if (arr[y + 1][x] == '1') return false;
	}
	return true;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: bfs, dp
결정적 깨달음		: 
시간복잡도		: O(N^2)
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////