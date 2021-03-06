#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
vector<int> adj[402];
int c[402][402], f[402][402], prv[402];

inline int chngM(int x);

void BFS(int st, int en);
void flow(int st, int en);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	int st = 0, en = 401;

	for (int i = 1; i <= N; i++) {
		adj[st].push_back(i);
		adj[i].push_back(st);
		c[st][i] = 1;
	}
	for (int i = 1; i <= M; i++) {
		adj[chngM(i)].push_back(en);
		adj[en].push_back(chngM(i));
		c[chngM(i)][en] = 1;
	}

	for (int i = 1; i <= N; i++) {
		int cnt; cin >> cnt;
		for (int l = 0; l < cnt; l++) {
			int next; cin >> next;
			adj[i].push_back(chngM(next));
			adj[chngM(next)].push_back(i);
			c[i][chngM(next)]++;
		}
	}

	int ans = 0;

	while (true) {
		BFS(st, en);

		if (prv[en] == -1) break;

		flow(st, en);
		ans++;
	}

	cout << ans;

	return 0;
}

inline int chngM(int x) {
	return x + 200;
}

void BFS(int st, int en) {
	memset(prv, -1, sizeof(prv));

	queue<int> q;
	q.push(st);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int next : adj[now]) {
			if (prv[next] != -1) continue;
			if (c[now][next] - f[now][next] > 0) {
				q.push(next);
				prv[next] = now;
				if (next == en) return;
			}
		}
	}
}

void flow(int st, int en) {
	int n = en;
	while (n != st) {
		f[prv[n]][n] += 1;
		f[n][prv[n]] -= 1;
		n = prv[n];
	}
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 에드몬드 카프 알고리즘
결정적 깨달음		:
시간복잡도		:
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////