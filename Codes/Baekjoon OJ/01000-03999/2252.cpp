#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAX = 32000;

int N, M;
vector<int> adj[MAX + 5];
bool visited[MAX + 5];
stack<int> stk;

void dfs(int v);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}
	
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) dfs(i);
	}

	while (!stk.empty()) {
		cout << stk.top() << ' ';
		stk.pop();
	}

	return 0;
}

void dfs(int v) {
	visited[v] = true;
	for (int next : adj[v]) {
		if (visited[next]) continue;
		dfs(next);
	}
	stk.push(v);
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: ���� ����
������ ������		: 
�ð����⵵		: O(|V|+|E|)
���� ����		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////