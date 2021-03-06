#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXV = ('Z' - 'A') + 1 + ('z' - 'a');

int N, c[MAXV + 5][MAXV + 5], f[MAXV + 5][MAXV + 5];
vector<int> adj[MAXV + 5];
int prv[MAXV + 5];

inline int CtoI(char x);
void BFS(int st, int en);
int flow(int st, int en);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//간선 정보 입력
	cin >> N;

	for (int i = 0; i < N; i++) {
		char cn1, cn2; int cap;
		cin >> cn1 >> cn2 >> cap;

		int n1 = CtoI(cn1), n2 = CtoI(cn2);
		c[n1][n2] = c[n2][n1] += cap;

		adj[n1].push_back(n2);
		adj[n2].push_back(n1);
	}

	//
	int total = 0, st = CtoI('A'), en = CtoI('Z');

	while (true) {
		BFS(st, en);

		if (prv[en] == -1) break;

		total += flow(st, en);
	}

	cout << total;

	return 0;
}

inline int CtoI(char x) {
	if (x <= 'Z') return x - 'A';
	else return ('Z' - 'A') + 1 + (x - 'a');
}

void BFS(int st, int en) {
	memset(prv, -1, sizeof(prv));

	queue<int> q;
	q.push(st);
	prv[st] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int next : adj[now]) {
			if (c[now][next] - f[now][next] > 0 && prv[next] == -1) {
				q.push(next);
				prv[next] = now;
				if (next == en) return;
			}
		}
	}
}

int flow(int st, int en) {
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
문제 해법		: 에드몬드 카프 알고리즘
결정적 깨달음		:
시간복잡도		: O(VE^2) (이해 못함)
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////