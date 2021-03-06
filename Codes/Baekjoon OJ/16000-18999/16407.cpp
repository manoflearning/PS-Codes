#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;

const int dy[] = { 1, -1, 0, 0 };
const int dx[] = { 0, 0, 1, -1 };
const int MAX = 30;
const int MAXV = 2 * MAX * MAX;
const int INF = 1e9 + 7;
const bool IN = true, OUT = false;

int R, C, cost[MAX + 5];
int st, en = MAXV + 1;
string arr[MAX + 5];
vector<int> adj[MAXV + 5];
int c[MAXV + 5][MAXV + 5], f[MAXV + 5][MAXV + 5], prv[MAXV + 5];

void input();
void graph_modeling(int sy, int sx);
inline int trans(int y, int x, bool isIN);
int max_flow();
void bfs();
int flow();

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();

	//그래프 모델링
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (arr[y][x] == 'B') {
				graph_modeling(y, x);
				y = R, x = C;
				break;
			}
		}
	}
	
	int ans = max_flow();
	if (ans != -1) cout << ans << '\n';
	else cout << -1 << '\n';

	return 0;
}

void input() {
	int type;
	cin >> C >> R >> type;
	for (int y = 0; y < R; y++) cin >> arr[y];
	for (int i = 0; i < type; i++) cin >> cost[i];
}

void graph_modeling(int sy, int sx) {
	st = trans(sy, sx, OUT);

	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			adj[trans(y, x, IN)].push_back(trans(y, x, OUT));
			adj[trans(y, x, OUT)].push_back(trans(y, x, IN));
			if (arr[y][x] != 'B' && arr[y][x] != '.') 
				c[trans(y, x, IN)][trans(y, x, OUT)] = cost[arr[y][x] - 'a'];
			else 
				c[trans(y, x, IN)][trans(y, x, OUT)] = INF;

			if (y == 0 || R - 1 == y || x == 0 || C - 1 == x) {
				adj[trans(y, x, OUT)].push_back(en);
				adj[en].push_back(trans(y, x, OUT));
				c[trans(y, x, OUT)][en] = INF;
				continue;
			}

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i], nx = x + dx[i];
				adj[trans(y, x, OUT)].push_back(trans(ny, nx, IN));
				adj[trans(ny, nx, IN)].push_back(trans(y, x, OUT));
				c[trans(y, x, OUT)][trans(ny, nx, IN)] = INF;
			}
		}
	}
}

inline int trans(int y, int x, bool isIN) {
	return isIN ? (y * MAX + x) : (MAXV / 2 + y * MAX + x);
}

int max_flow() {
	int ret = 0;
	while (true) {
		bfs();

		if (prv[en] == -1) break;

		ret += flow();
		if (ret >= INF) return -1;
	}
	return ret;
}

void bfs() {
	memset(prv, -1, sizeof(prv));

	queue<int> q;
	q.push(st);
	prv[st] = 0;

	while (!q.empty() && prv[en] == -1) {
		int now = q.front();
		q.pop();
		
		for (int next : adj[now]) {
			if (prv[next] == -1 && c[now][next] - f[now][next] > 0) {
				prv[next] = now;
				q.push(next);
			}
		}
	}
}

int flow() {
	int n = en, block = INF;
	while (n != st) {
		block = min(block, c[prv[n]][n] - f[prv[n]][n]);
		n = prv[n]; 
	}
	n = en;
	while (n != st) {
		f[prv[n]][n] += block;
		f[n][prv[n]] -= block;
		n = prv[n];
	}
	return block;
}
/*//////////////////////////////////////////////////////////////////
문제 해법		: 최소 컷
결정적 깨달음		: 정점을 들어가는 정점과 나오는 정점으로 분할.
시간복잡도		: O(|V||E|^2)
오답 원인		: 1.
				  2.
*///////////////////////////////////////////////////////////////////