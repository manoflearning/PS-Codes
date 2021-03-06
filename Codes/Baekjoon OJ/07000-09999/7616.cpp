#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int MAXV = 2 * 1e3;

int K, N, st, en;
int c[MAXV + 5][MAXV + 5], f[MAXV + 5][MAXV + 5];
vector<int> adj[MAXV + 5];
int prv[MAXV + 5];

void init();
void scan();
inline int trans(int x, bool indeg);
int max_flow();
void bfs();
int flow();
void print();

int main() {
	//cin.tie(NULL); cout.tie(NULL);
	//ios_base::sync_with_stdio(false);

	st = trans(1, false), en = trans(2, true);

	for (int test = 1; ; test++) {
		init();

		scanf("%d %d", &K, &N);

		if (K == 0 && N == 0) break;

		scan();

		int total = max_flow();

		printf("Case %d:\n", test);
		if (total >= K) {
			for (int i = 0; i < K; i++) print();
		}
		else printf("Impossible\n");
		printf("\n");
	}

	return 0;
}

void init() {
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
	for (int i = 0; i < MAXV + 5; i++)
		adj[i].clear();
}

void scan() {
	for (int i = 1; i <= N; i++) {
		vector<bool> exist(N + 1, false);

		while (true) {
			int a; char x;
			scanf("%d%c", &a, &x);

			if (!exist[a]) {
				adj[trans(a, false)].push_back(trans(i, true));
				adj[trans(i, true)].push_back(trans(a, false));
				adj[trans(i, false)].push_back(trans(a, true));
				adj[trans(a, true)].push_back(trans(i, false));
				exist[a] = true;
			}

			c[trans(a, false)][trans(i, true)]++;
			c[trans(i, false)][trans(a, true)]++;

			if (x == '\n') break;
		}

		adj[trans(i, true)].push_back(trans(i, false));
		c[trans(i, true)][trans(i, false)] = 1;
	}
}

inline int trans(int x, bool indeg) {
	return indeg ? 2 * (x - 1) : 2 * (x - 1) + 1;
}

int max_flow() {
	int ret = 0;
	while (true) {
		bfs();

		if (prv[en] == -1) break;

		ret += flow();

		if (ret >= K) break;
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
	int n = en;
	while (n != st) {
		f[prv[n]][n] += 1;
		f[n][prv[n]] -= 1;
		n = prv[n];
	}
	return 1;
}

void print() {
	int path[MAXV + 5];
	memset(path, -1, sizeof(path));
	memset(prv, -1, sizeof(prv));

	queue<int> q;
	q.push(st);
	prv[st] = 0;

	while (!q.empty() && prv[en] == -1) {
		int now = q.front();
		q.pop();

		for (int next : adj[now]) {
			if (prv[next] == -1 && f[now][next] > 0) {
				prv[next] = now;
				path[now] = next;
				q.push(next);
				break;
			}
		}
	}

	int n = st;
	while (n != en) {
		if (n % 2) printf("%d ", n / 2 + 1);
		f[n][path[n]]--;
		f[path[n]][n]++;
		n = path[n];
	}
	printf("%d\n", en / 2 + 1);
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 네트워크 유량
결정적 깨달음		: 
시간복잡도		: 
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////