#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXV = 300;
const int INF = 1e9 + 7;

//scc
int N, label[MAXV + 5], lCnt;
int sNum[MAXV + 5], sCnt;
vector<int> adj[MAXV + 5];
stack<int> stk;
bool finished[MAXV + 5];
vector<vector<int>> SCC;

//scc 그래프
int sAdj[MAXV + 5][MAXV + 5];
vector<pair<int, int>> sEdges;

int DFS(int v);
void floyd();

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;

	while (T--) {
		lCnt = sCnt = 0;
		SCC.clear(); sEdges.clear();
		memset(label, -1, sizeof(label));
		memset(sNum, 0, sizeof(sNum));
		memset(finished, 0, sizeof(finished));
		memset(sAdj, -1, sizeof(sAdj));
		for (int i = 0; i < MAXV + 5; i++)
			adj[i].clear();

		//테스트케이스 시작
		cin >> N;

		for (int u = 1; u <= N; u++) {
			for (int v = 1; v <= N; v++) {
				char x; cin >> x;
				if (x == '1' && u != v) adj[u].push_back(v);
			}
		}

		//dfs 스패닝 트리
		for (int v = 1; v <= N; v++)
			if (label[v] == -1) DFS(v);

		//scc 그래프
		for (int v = 1; v <= N; v++) {
			int sV = sNum[v];
			for (int next : adj[v]) {
				int sNext = sNum[next];
				sAdj[sV][sNext] = 1;
			}
		}

		//간선 개수 세기
		floyd();
		
		int ans = sEdges.size();
		for (int v = 0; v < sCnt; v++)
			if (SCC[v].size() != 1) ans += SCC[v].size();

		cout << ans << '\n';
		
		//간선 출력
		for (auto v : sEdges)
			cout << SCC[v.first][0] << ' ' << SCC[v.second][0] << '\n';
		for (int v = 0; v < sCnt; v++) {
			if (SCC[v].size() != 1) 
				cout << SCC[v][SCC[v].size() - 1] << ' ' << SCC[v][0] << '\n';
			for (int i = 1; i < SCC[v].size(); i++)
				cout << SCC[v][i - 1] << ' ' << SCC[v][i] << '\n';
		}
		cout << '\n';
	}

	return 0;
}

int DFS(int v) {
	label[v] = lCnt++;
	stk.push(v);

	int ret = label[v];
	for (int next : adj[v]) {
		if (label[next] == -1) ret = min(ret, DFS(next));
		else if (!finished[next]) ret = min(ret, label[next]);
	}

	if (ret == label[v]) {
		vector<int> vSCC;
		while (true) {
			int t = stk.top();
			stk.pop();

			vSCC.push_back(t);
			sNum[t] = sCnt;
			finished[t] = true;

			if (t == v) break;
		}

		SCC.push_back(vSCC);
		sCnt++;
	}

	return ret;
}

void floyd() {
	for (int v = 0; v < sCnt; v++) sAdj[v][v] = 0;

	for (int k = 0; k < sCnt; k++) {
		for (int u = 0; u < sCnt; u++) {
			if (sAdj[u][k] == -1) continue;
			for (int v = 0; v < sCnt; v++) {
				if (sAdj[k][v] == -1) continue;
				sAdj[u][v] = max(sAdj[u][v], sAdj[u][k] + sAdj[k][v]);
			}
		}
	}

	for (int u = 0; u < sCnt; u++) {
		for (int v = 0; v < sCnt; v++) {
			if (sAdj[u][v] == 1) sEdges.push_back({ u, v });
		}
	}
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: SCC + 플로이드 와샬 알고리즘
결정적 깨달음		: 모든 정점 쌍에 대해 최장거리를 구했을 때, 최장거리가 1인 정점 간의 간선만이 최소한으로 필요하다.
시간복잡도		: O(|V|^3)
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////