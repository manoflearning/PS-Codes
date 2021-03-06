#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int MAXV = 300 + 5;

int N;
int c[MAXV][MAXV], f[MAXV][MAXV], prv[MAXV];
vector<int> adj[MAXV];
vector<pii> edges;

void init();
void bfs();
void flow();

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;

	while (T--) {
		init();
		
		int M;
		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			int a, b, cap;
			cin >> a >> b >> cap;
			adj[a].push_back(b);
			adj[b].push_back(a);
			c[a][b] += cap;
			edges.push_back({ a, b });
		}

		//
		while (true) {
			bfs();

			if (prv[N] == -1) break;

			flow();
		}
		
		//
		int ans = 0;
		for (pii e : edges) {
			int st = e.first, en = e.second;
			memset(prv, -1, sizeof(prv));

			queue<int> q;
			q.push(st);

			while (!q.empty()) {
				int now = q.front();
				q.pop();

				for (int next : adj[now]) {
					if (prv[next] == -1 && c[now][next] - f[now][next] > 0) {
						prv[next] = now; 
						q.push(next);
					}
				}
			}

			if (prv[en] == -1) ans++;
		}

		cout << ans << endl;
	}

	return 0;
}

void init() {
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
	for (int i = 0; i < MAXV; i++)
		adj[i].clear();
	edges.clear();
}

void bfs() {
	memset(prv, -1, sizeof(prv));

	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int next : adj[now]) {
			if (prv[next] == -1 && c[now][next] - f[now][next] > 0) {
				q.push(next);
				prv[next] = now;
				if (next == N) return;
			}
		}
	}
}

void flow() {
	int n = N, block = 1001;
	while (n != 1) {
		block = min(block, c[prv[n]][n] - f[prv[n]][n]);
		n = prv[n];
	}
	n = N;
	while (n != 1) {
		f[prv[n]][n] += block;
		f[n][prv[n]] -= block;
		n = prv[n];
	}
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 네트워크 유량
결정적 깨달음		: 
시간복잡도		:
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////