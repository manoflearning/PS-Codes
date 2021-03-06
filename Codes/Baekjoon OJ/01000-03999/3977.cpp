#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXV = 1e5;

int N, label[MAXV + 5], labelCnt;
int SCCnum[MAXV + 5], SCCcnt, indegree[MAXV + 5];
vector<int> adj[MAXV + 5];
stack<int> S;
vector<vector<int>> SCC;
bool finished[MAXV + 5];

int DFS(int v);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;

	while (T--) {
		SCC.clear();
		labelCnt = SCCcnt = 0;
		memset(label, -1, sizeof(label));
		memset(finished, 0, sizeof(finished));
		memset(indegree, 0, sizeof(indegree));
		for (int i = 0; i < MAXV + 5; i++)
			adj[i].clear();

		//테스트케이스 시작
		int M;
		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			int a, b; cin >> a >> b;
			adj[a].push_back(b);
		}

		//DFS 스패닝 트리
		for (int v = 0; v < N; v++)
			if (label[v] == -1) DFS(v);

		//indegree
		for (int v = 0; v < N; v++) {
			for (int next : adj[v]) {
				if (SCCnum[v] == SCCnum[next]) continue;
				indegree[SCCnum[next]]++;
			}
		}

		//indegree가 0인 SCC가 0 또는 1개이어야 함
		int indegCnt = 0, flag;
		for(int v = 0; v < SCCcnt; v++)
			if (indegree[v] == 0) {
				flag = v;
				indegCnt++;
			}

		if (indegCnt >= 2) cout << "Confused\n";
		//그래프의 SCC가 하나인 경우. 즉 그래프의 모든 정점이 하나의 SCC에 포함되는 경우
		else if (indegCnt == 0) {
			for (int v = 0; v < N; v++)
				cout << v << '\n';
		}
		else {
			sort(SCC[flag].begin(), SCC[flag].end());
			for (int v : SCC[flag])
				cout << v << '\n';
		}
		cout << '\n';
	}

	return 0;
}

int DFS(int v) {
	label[v] = labelCnt++;
	S.push(v);

	int ret = label[v];
	for (int next : adj[v]) {
		if (label[next] == -1) ret = min(ret, DFS(next));
		else if (!finished[next]) ret = min(ret, label[next]);
	}

	if (ret == label[v]) {
		vector<int> vSCC;
		while (true) {
			int t = S.top();
			S.pop();

			vSCC.push_back(t);
			SCCnum[t] = SCCcnt;
			finished[t] = true;
			
			if (t == v) break;
		}

		SCC.push_back(vSCC);
		SCCcnt++;
	}

	return ret;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: SCC
결정적 깨달음		: 
시간복잡도		: O(|V| + |E|)
오답 원인		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////