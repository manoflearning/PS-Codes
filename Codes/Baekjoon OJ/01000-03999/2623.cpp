#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1000;

int N, indegree[MAX + 5];
vector<int> adj[MAX + 5], arr;
bool isCycle;

void topological_sort();

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int M;
	cin >> N >> M;

	//유향 그래프 형성
	for (int i = 0; i < M; i++) {
		int x; cin >> x;
		vector<int> edges(x);
		for (int i = 0; i < x; i++)
			cin >> edges[i];
		for (int i = 0; i < x - 1; i++) {
			adj[edges[i]].push_back(edges[i + 1]);
			indegree[edges[i + 1]]++;
		}
	}

	topological_sort();

	if (isCycle) cout << 0;
	else {
		for (int i = 0; i < arr.size(); i++)
			cout << arr[i] << '\n';
	}

	return 0;
}

void topological_sort() {
	queue<int> q;

	for (int i = 1; i <= N; i++)
		if (indegree[i] == 0) q.push(i);

	for (int i = 0; i < N; i++) {
		if (q.empty()) {
			isCycle = true;
			break;
		}

		int v = q.front();
		q.pop();

		arr.push_back(v);
		
		for (int next : adj[v]) {
			indegree[next]--;
			if (indegree[next] == 0) q.push(next);
		}
	}
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 위상정렬
결정적 깨달음		:
시간복잡도		: 
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////