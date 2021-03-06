#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

const int MAXV = 1e2;

struct dn {
	int d, n;
};

int N, cost[MAXV + 5][MAXV + 5], indeg[MAXV + 5];
vector<dn> adj[MAXV + 5];
stack<int> stk;
vector<int> basic, res;
bool visited[MAXV + 5];

void topological_sort();
void DFS(int v);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int v, u, d; cin >> v >> u >> d;
		adj[u].push_back({ d, v });
		indeg[v]++;
	}

	for (int v = 1; v <= N; v++)
		if (indeg[v] == 0) {
			basic.push_back(v);
			cost[v][v] = 1;
		}

	topological_sort();

	for (int i = 0; i < res.size(); i++) {
		int v = res[i];

		for (auto next : adj[v]) {
			for (int b : basic) {
				cost[b][next.n] += cost[b][v] * next.d;
			}
		}
	}

	for (int b : basic) {
		cout << b << ' ' << cost[b][N] << '\n';
	}

	return 0;
}

void topological_sort() {
	for (int v = 1; v <= N; v++)
		if (!visited[v]) DFS(v);

	while (!stk.empty()) {
		res.push_back(stk.top());
		stk.pop();
	}
}
void DFS(int v) {
	visited[v] = true;
	for (auto next : adj[v]) {
		if (!visited[next.n]) DFS(next.n);
	}
	stk.push(v);
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 위상 정렬
결정적 깨달음		:
시간복잡도		: O(|N|*(|V| + |E|))
오답 원인		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////