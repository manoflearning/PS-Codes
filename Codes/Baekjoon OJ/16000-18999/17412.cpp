#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 401;

int N;
vector<int> adj[MAX];
int c[MAX][MAX], f[MAX][MAX], prv[MAX];

void BFS();
void flow();

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int P;  cin >> N >> P;

	for (int i = 0; i < P; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		c[a][b] += 1;
	}

	int ans = 0;
	while (true) {
		BFS();
		
		if (prv[2] == -1) break;
		
		flow();
		ans++;
	}

	cout << ans;

	return 0;
}

void BFS() {
	memset(prv, -1, sizeof(prv));

	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int next : adj[now]) {
			if (prv[next] != -1) continue;
			if (c[now][next] - f[now][next] > 0) {
				prv[next] = now;
				q.push(next);
				if (next == 2) return;
			}
		}
	}
}
void flow() {
	int n = 2;
	while (n != 1) {
		f[prv[n]][n] += 1;
		f[n][prv[n]] -= 1;
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