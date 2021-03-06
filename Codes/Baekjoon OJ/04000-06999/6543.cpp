#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXV = 5 * 1e3;

int N, label[MAXV + 5], labelCnt;
int SCCnum[MAXV + 5], SCCcnt, outdegree[MAXV + 5];
vector<int> adj[MAXV + 5];
stack<int> S;
bool finished[MAXV + 5];
vector<vector<int>> SCC;

int DFS(int v);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		labelCnt = SCCcnt = 1;
		SCC.clear();
		memset(label, 0, sizeof(label));
		memset(finished, 0, sizeof(finished));
		memset(SCCnum, 0, sizeof(SCCnum));
		memset(outdegree, 0, sizeof(outdegree));
		for (int i = 0; i < MAXV + 5; i++)
			adj[i].clear();

		//테스트케이스 시작
		cin >> N;
		if (N == 0) break;

		int M; cin >> M;
		for (int i = 0; i < M; i++) {
			int a, b; cin >> a >> b;
			adj[a].push_back(b);
		}

		//DFS 스패닝 트리 형성
		for (int v = 1; v <= N; v++)
			if (label[v] == 0) DFS(v);

		//SCC의 outdegree 탐색
		for (int v = 1; v <= N; v++) {
			for (int next : adj[v]) {
				if (SCCnum[v] == SCCnum[next]) continue;
				outdegree[SCCnum[v]]++;
			}
		}

		//outdegree가 0인 모든 SCC의 모든 정점 탐색
		vector<int> ans;
		for (int SCCv = 1; SCCv < SCCcnt; SCCv++) {
			if (outdegree[SCCv] == 0) {
				for (int v : SCC[SCCv - 1]) 
					ans.push_back(v);
			}
		}

		//출력
		if (ans.empty()) cout << '\n';
		else {
			sort(ans.begin(), ans.end());
			for (int v : ans) 
				cout << v << ' ';
			cout << '\n';
		}
	}

	return 0;
}

int DFS(int v) {
	label[v] = labelCnt++;
	S.push(v);

	int ret = label[v];
	for (int next : adj[v]) {
		if (label[next] == 0) ret = min(ret, DFS(next));
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
문제 해법		: 강한 연결 요소 (SCC)
결정적 깨달음		: outdegree가 0인 모든 SCC의 모든 노드를 출력한다
시간복잡도		: O(|E| + |V|lg|V|)
오답 원인		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////