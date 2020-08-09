#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100;
const int INF = 1e9 + 7;

struct dv {
	int d, v;
};

int N, M;
vector<dv> adj[MAX + 5];
int prv[MAX + 5], upper[MAX + 5];
bool cycle[MAX + 5];

void DFS(int v);
void print(int v);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	fill(upper, upper + MAX + 5, INF);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ -w, v });
	}

	upper[1] = 0;

	bool update;
	for (int i = 0; i < N - 1; i++) {
		update = false;
		for (int now = 1; now <= N; now++) {
			for (dv next : adj[now]) {
				if (upper[next.v] > upper[now] + next.d) {
					upper[next.v] = upper[now] + next.d;
					prv[next.v] = now;
					update = true;
				}
			}
		}

		if (!update) break;
	}

	for(int now = 1; now <= N; now++) {
		for (dv next : adj[now]) {
			if (upper[next.v] > upper[now] + next.d) {
				upper[next.v] = upper[now] + next.d;
				DFS(now);
			}
		}
	}

	if (cycle[N]) cout << -1;
	else {
		if (upper[N] >= INF - N * 1000) cout << -1;
		else print(N);
	}

	return 0;
}

void DFS(int v) {
	cycle[v] = true;
	for (dv next : adj[v]) {
		if (cycle[next.v]) continue;
		DFS(next.v);
	}
}
void print(int v) {
	if (prv[v] != 0) print(prv[v]);
	cout << v << ' ';
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: ����-���� �˰�����, DFS.
������ ������		: ���� ����Ŭ���� N�� �������� ���� ��ΰ� �����Ѵٸ�, �ִܰ�δ� �������� �ʴ´�. �׷��� �ʴٸ�, ���� �׷����� ���� ����Ŭ�� �����Ѵٰ� �ص� �ִܰ�δ� �����Ѵ�.
�ð����⵵		: 
���� ����		: 1. upper[s]�� 0���� �ʱ�ȭ �ؾ���.
				  2.
*/////////////////////////////////////////////////////////////////////