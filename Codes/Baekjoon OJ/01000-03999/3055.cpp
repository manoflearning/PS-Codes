#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define vc vector<char>
#define vvc vector<vector<char>>
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>

const int dy[] = { 0, 1, 0, -1 };
const int dx[] = { 1, 0, -1, 0 };
const int INF = 1e9 + 7;

int R, C;
vvc arr(55, vc(55));
vvi timeW(55, vi(55, INF)), timeS(55, vi(55, INF));

void bfsW(int sy, int sx);
void bfsS(int sy, int sx);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> R >> C;

	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cin >> arr[y][x];
		}
	}

	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (arr[y][x] == '*') bfsW(y, x);
		}
	}

	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (arr[y][x] == 'S') bfsS(y, x);
		}
	}

	int ans = INF;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (arr[y][x] == 'D') ans = min(ans, timeS[y][x]);
			//cout << timeS[y][x] << ' ';
		}
		//cout << '\n';
	}

	if (ans == INF) cout << "KAKTUS";
	else cout << ans;

	return 0;
}

void bfsW(int sy, int sx) {
	queue<pii> q;
	q.push({ sy, sx });
	timeW[sy][sx] = 0;

	while (!q.empty()) {
		int y = q.front().first, x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < 0 || R <= ny || nx < 0 || C <= nx) continue;
			if (arr[ny][nx] == 'X' || arr[ny][nx] == 'D' || arr[ny][nx] == '*') continue;
			if (timeW[ny][nx] <= timeW[y][x] + 1) continue;

			timeW[ny][nx] = timeW[y][x] + 1;
			q.push({ ny, nx });
		}
	}
}

void bfsS(int sy, int sx) {
	queue<pii> q;
	q.push({ sy, sx });
	timeS[sy][sx] = 0;

	while (!q.empty()) {
		int y = q.front().first, x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < 0 || R <= ny || nx < 0 || C <= nx) continue;
			if (arr[ny][nx] == 'X' || arr[ny][nx] == 'S') continue;
			if (timeS[ny][nx] <= timeS[y][x] + 1) continue;
			if (timeS[y][x] + 1 >= timeW[ny][nx]) continue;

			timeS[ny][nx] = timeS[y][x] + 1;
			q.push({ ny, nx });
		}
	}
}