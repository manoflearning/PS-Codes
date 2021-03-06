#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define pii pair<int, int>
using namespace std;

const int MAX = 12, MAXP = 100, MAXE = 40, MAXT = 200;
const int dy[] = { 0, 0, -1, 1 };
const int dx[] = { 1, -1, 0, 0 };

int R, C, A[MAXP + 5], B[MAXE * MAXT + 5];
int people[MAX + 5][MAX + 5], escape[MAX + 5][MAX + 5], pCnt, eCnt;
char arr[MAX + 5][MAX + 5];
int dist[MAXP + 5][MAXE + 5];
vector<int> adj[MAXP + 5];
bool visited[MAXP + 5];

void input();
void dist_cal();
void bfs(int sy, int sx);
int bSearch(int L, int R);
void init();
inline int trans(int e, int t);
int bMatch();
bool dfs(int a);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	input();

	dist_cal();

	int ans = bSearch(0, 1000);
	if (ans == 1000) cout << "impossible" << '\n';
	else cout << ans << '\n';

	return 0;
}

void input() {
	cin >> R >> C;

	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			cin >> arr[y][x];

			if (arr[y][x] == '.') {
				people[y][x] = ++pCnt;
			}
			else if (arr[y][x] == 'D') {
				if ((y == 1 || y == R) && (x == 1 || x == C)) continue;
				escape[y][x] = ++eCnt;
			}
		}
	}
}

void dist_cal() {
	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			if (arr[y][x] == '.') bfs(y, x);
		}
	}
}

void bfs(int sy, int sx) {
	vector<vector<bool>> visited(R + 1, vector<bool>(C + 1));

	struct yxd {
		int y, x, d;
	};

	queue<yxd> q;
	q.push({ sy, sx, 0 });
	visited[sy][sx] = true;

	while (!q.empty()) {
		int y = q.front().y, x = q.front().x, d = q.front().d;
		q.pop();

		if (arr[y][x] == 'D') {
			dist[people[sy][sx]][escape[y][x]] = d;
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (y < 1 || R < y || x < 1 || C < x) continue;
			if (arr[ny][nx] == 'X') continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = true;
			q.push({ ny, nx, d + 1 });
		}
	}
}

int bSearch(int L, int R) {
	if (L == R) return L;

	init();

	int mid = (L + R) / 2;
	for (int p = 1; p <= pCnt; p++) {
		for (int e = 1; e <= eCnt; e++) {
			//갈 수 없는 경우
			if (dist[p][e] == 0) continue;
			
			for (int i = dist[p][e]; i <= mid; i++) {
				adj[p].push_back(trans(e, i));
			}
		}
	}

	int ret = bMatch();

	if (ret == pCnt) return bSearch(L, mid);
	else return bSearch(mid + 1, R);
}

void init() {
	for (int i = 0; i < MAXP + 5; i++)
		adj[i].clear();
}

inline int trans(int e, int t) {
	return MAXE * t + e;
}

int bMatch() {
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));

	int ret = 0;
	for (int i = 1; i <= pCnt; i++) {
		memset(visited, 0, sizeof(visited));
		if (dfs(i)) ret++;
	}
	return ret;
}

bool dfs(int a) {
	visited[a] = true;
	for (int b : adj[a]) {
		if (B[b] == -1 || (!visited[B[b]] && dfs(B[b]))) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}
/*//////////////////////////////////////////////////////////////////
문제 해법		: 이분 탐색, 이분 매칭
결정적 깨달음		: 
시간복잡도		: 
오답 원인		: 1. 
				  2.
*///////////////////////////////////////////////////////////////////