#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 500, MAXV = 2 * MAX;
const int INF = 1e9 + 7;

int N, st = 0, en = MAXV + 1;
int c[MAXV + 5][MAXV + 5], f[MAXV + 5][MAXV + 5];
int d[MAXV + 5][MAXV + 5], prv[MAXV + 5];
vector<int> adj[MAXV + 5], graph[MAX + 5];
bool wCoin[MAX + 5], wNode[MAX + 5];

void init();
void input();
void graph_modeling();
void bfs(int st);
inline int trans(int x);
int mcmf();
void spfa();
int flow();

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;

	while (T--) {
		init();

		input();

		graph_modeling();

		int ans = mcmf();
		cout << ans << '\n';
	}

	return 0;
}

void init() {
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
	memset(d, 0, sizeof(d));
	for (int i = 0; i < MAXV + 5; i++)
		adj[i].clear();
	for (int i = 0; i < MAX + 5; i++)
		graph[i].clear();
}

void input() {
	int M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) cin >> wNode[i];
	for (int i = 1; i <= N; i++) cin >> wCoin[i];
}

void graph_modeling() {
	for (int i = 1; i <= N; i++) {
		//�ҽ��� ��� ���� ����
		if (wCoin[i]) {
			adj[st].push_back(i);
			adj[i].push_back(st);
			c[st][i] = 1;
		}
		//��ũ�� ��� ���� ����
		if (wNode[i]) {
			adj[trans(i)].push_back(en);
			adj[en].push_back(trans(i));
			c[trans(i)][en] = 1;
		}
	}

	for (int i = 1; i <= N; i++)
		if (wCoin[i]) bfs(i);
}

void bfs(int sv) {
	vector<int> dist(MAX + 5, -1);

	queue<int> q;
	q.push(sv);
	dist[sv] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (wNode[now]) {
			adj[sv].push_back(trans(now));
			adj[trans(now)].push_back(sv);
			c[sv][trans(now)] = INF;
			d[sv][trans(now)] = dist[now];
			d[trans(now)][sv] = -dist[now];
		}

		for (int next : graph[now]) {
			if (dist[next] == -1) {
				dist[next] = dist[now] + 1;
				q.push(next);
			}
		}
	}
}

inline int trans(int x) {
	return MAX + x;
}

int mcmf() {
	int ret = 0;
	while (true) {
		spfa();

		if (prv[en] == -1) break;

		ret += flow();
	}
	return ret;
}

void spfa() {
	memset(prv, -1, sizeof(prv));
	vector<int> dist(MAXV + 5, INF);
	vector<bool> inQ(MAXV + 5);

	queue<int> q;
	q.push(st);
	dist[st] = 0, inQ[st] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		inQ[now] = false;

		for (int next : adj[now]) {
			if (dist[now] + d[now][next] < dist[next] && c[now][next] - f[now][next] > 0) {
				dist[next] = dist[now] + d[now][next];
				prv[next] = now;
				if (!inQ[next]) {
					inQ[next] = true;
					q.push(next);
				}
			}
		}
	}
}

int flow() {
	int ret = 0, block = INF;
	for (int i = en; i != st; i = prv[i]) {
		block = min(block, c[prv[i]][i] - f[prv[i]][i]);
	}
	for (int i = en; i != st; i = prv[i]) {
		ret += d[prv[i]][i] * block;
		f[prv[i]][i] += block;
		f[i][prv[i]] -= block;
	}
	return ret;
}