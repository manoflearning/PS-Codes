#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 7;
const int MAXM = 1000, MAXN = 100;
const int MAXV = MAXM + MAXN;

int M, N, st = 0, en = MAXV + 1;
bool canGo[MAXN + 5][MAXM + 5];
vector<int> adj[MAXV + 5];
int c[MAXV + 5][MAXV + 5], f[MAXV + 5][MAXV + 5], prv[MAXV + 5];

void scan();
inline int trans(int x);
void redist();
int max_flow();
void bfs();
int flow();

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	scan();

	//돼지 재분배용 간선
	redist();
	
	int ans = max_flow();
	cout << ans << '\n';

	return 0;
}

void scan() {
	cin >> M >> N;

	for (int i = 1; i <= M; i++) {
		adj[trans(i)].push_back(en);
		adj[en].push_back(trans(i));
		cin >> c[trans(i)][en];
	}

	for (int i = 1; i <= N; i++) {
		int cnt; cin >> cnt;
		for (int l = 0; l < cnt; l++) {
			int x; cin >> x;
			adj[i].push_back(trans(x));
			adj[trans(x)].push_back(i);
			c[i][trans(x)] = INF;
			canGo[i][x] = true;
		}

		adj[st].push_back(i);
		adj[i].push_back(st);
		cin >> c[st][i];
	}
}

inline int trans(int x) {
	return MAXN + x;
}

void redist() {
	for (int i = 2; i <= N; i++) {
		for (int l = i - 1; l >= 1; l--) {
			for (int j = 1; j <= M; j++) {
				if (canGo[i][j] && canGo[l][j]) {
					adj[i].push_back(l);
					adj[l].push_back(i);
					c[i][l] = INF;
					break;
				}
			}
		}
	}
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
문제 해법		: 최대 유량
결정적 깨달음		:
시간복잡도		: O(|V||E|^2)
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////