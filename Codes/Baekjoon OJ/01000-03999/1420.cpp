#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int dy[] = { 0, 0, -1, 1 };
const int dx[] = { -1, 1, 0, 0 };
const int MAX = 100;
const int MAXV = 2 * MAX * MAX;
const int INF = 1e9 + 7;
const bool IN = true, OUT = false;

struct edge {
	int v, c, f;
	edge* rev;
	edge(int v1, int c1): v(v1), c(c1), f(0), rev(nullptr){}
	int recidual() {
		return c - f;
	}
	void addFlow(int f1) {
		f += f1;
		rev->f -= f1;
	}
};

int R, C, st, en;
string arr[MAX + 5];
vector<edge*> adj[MAXV + 5];
int prv[MAXV + 5];
edge* path[MAXV + 5];

void input();
void graph_modeling();
inline int trans(int y, int x, bool isIN);
int max_flow();
void bfs();
int flow();

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();

	graph_modeling();

	int ans = max_flow();
	cout << ans << '\n';

	return 0;
}

void input() {
	cin >> R >> C;
	for (int y = 0; y < R; y++) cin >> arr[y];
}

void graph_modeling() {
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (arr[y][x] == '#') continue;

			if (arr[y][x] == 'K') st = trans(y, x, OUT);
			if (arr[y][x] == 'H') en = trans(y, x, IN);

			edge* e1 = new edge(trans(y, x, OUT), 1), * e2 = new edge(trans(y, x, IN), 0);
			e1->rev = e2, e2->rev = e1;
			adj[trans(y, x, IN)].push_back(e1);
			adj[trans(y, x, OUT)].push_back(e2);

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i], nx = x + dx[i];
				if (ny < 0 || R <= ny || nx < 0 || C <= nx) continue;
				if (arr[ny][nx] == '#') continue;
				edge* e1 = new edge(trans(ny, nx, IN), INF), * e2 = new edge(trans(y, x, OUT), 0);
				e1->rev = e2, e2->rev = e1;
				adj[trans(y, x, OUT)].push_back(e1);
				adj[trans(ny, nx, IN)].push_back(e2);
			}
		}
	}
}

inline int trans(int y, int x, bool isIN) {
	return isIN ? y * MAX + x : MAXV / 2 + y * MAX + x;
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

		for (auto* e : adj[now]) {
			int next = e->v;
			if (prv[next] == -1 && e->recidual() > 0) {
				prv[next] = now;
				path[next] = e;
				q.push(next);
			}
		}
	}
}

int flow() {
	int n = en, block = INF;
	while (n != st) {
		block = min(block, path[n]->recidual());
		n = prv[n];
	}
	n = en;
	while (n != st) {
		path[n]->addFlow(block);
		n = prv[n];
	}
	return block;
}
/*//////////////////////////////////////////////////////////////////
문제 해법		: 최소 컷
결정적 깨달음		:
시간복잡도		: O(|V||E|^2)
오답 원인		: 1.
				  2.
*///////////////////////////////////////////////////////////////////