#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define pii pair<int, int>

const int MAX = 50;
const int MAXV = MAX * MAX;
const int INF = 1e9 + 7;

int Y, X, arr[MAX + 5][MAX + 5];
int st, en, c[MAXV + 5][MAXV + 5], f[MAXV + 5][MAXV + 5];
vector<int> adj[MAXV + 5];
vector<pii> edge;
int prv[MAXV + 5];

void init();
void scan();
inline int trans(int y, int x);
int max_flow();
void bfs();
int flow();

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int T; cin >> T;

	while (T--) {
		init();

		cin >> Y >> X;
		st = 0, en = trans(Y, X) + 1;

		scan();

		int total = max_flow();
	
		for (pii e : edge) {
			int now = e.first, next = e.second;
			total += c[now][next] - f[now][next];
		}

		cout << total << endl;
	}

	return 0;
}

void init() {
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
	for (int i = 0; i < MAXV + 5; i++)
		adj[i].clear();
	edge.clear();
}

void scan() {
	for (int y = 1; y <= Y; y++) {
		for (int x = 1; x <= X; x++) {
			cin >> arr[y][x];

			bool strt = (y % 2 && x % 2) || (!(y % 2) && !(x % 2));
			if (strt) {
				adj[st].push_back(trans(y, x));
				adj[trans(y, x)].push_back(st);
				c[st][trans(y, x)] = arr[y][x];
				edge.push_back({ st, trans(y, x) });
			}
			else {
				adj[trans(y, x)].push_back(en);
				adj[en].push_back(trans(y, x));
				c[trans(y, x)][en] = arr[y][x];
				edge.push_back({ trans(y, x), en });
			}
			if (strt) {
				if (1 < x) {
					adj[trans(y, x)].push_back(trans(y, x - 1));
					adj[trans(y, x - 1)].push_back(trans(y, x));
					c[trans(y, x)][trans(y, x - 1)] = INF;
				}
				if (x < X) {
					adj[trans(y, x)].push_back(trans(y, x + 1));
					adj[trans(y, x + 1)].push_back(trans(y, x));
					c[trans(y, x)][trans(y, x + 1)] = INF;
				}
				if (1 < y) {
					adj[trans(y, x)].push_back(trans(y - 1, x));
					adj[trans(y - 1, x)].push_back(trans(y, x));
					c[trans(y, x)][trans(y - 1, x)] = INF;
				}
				if (y < Y) {
					adj[trans(y, x)].push_back(trans(y + 1, x));
					adj[trans(y + 1, x)].push_back(trans(y, x));
					c[trans(y, x)][trans(y + 1, x)] = INF;
				}
			}
		}
	}
}

inline int trans(int y, int x) {
	return (y - 1) * X + x;
}

int max_flow() {
	int ret = 0;
	while (true) {
		bfs();

		if (prv[en] == -1) break;

		ret += flow();
	}
	return ret;
}

void bfs() {
	memset(prv, -1, sizeof(prv));
	
	queue<int> q;
	q.push(st);
	prv[st] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int next : adj[now]) {
			if (prv[next] == -1 && c[now][next] - f[now][next] > 0) {
				prv[next] = now;
				q.push(next);
				if (next == en) return;
			}
		}
	}
}

int flow() {
	int n = en, block = 1001;
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
/*////////////////////////////////////////////////////////////////////
문제 해법		: 네트워크 유량
결정적 깨달음		: 
시간복잡도		: 
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////