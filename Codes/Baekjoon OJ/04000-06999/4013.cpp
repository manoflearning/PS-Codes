#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXV = 5 * 1e5;

int N, cost[MAXV + 5], st;
bool isRestaurant[MAXV + 5];
vector<int> adj[MAXV + 5];

//scc
int label[MAXV + 5], lCnt, SCCnum[MAXV + 5], SCCcnt;
stack<int> S;
bool finished[MAXV + 5];
vector<vector<int>> SCC;

//scc 그래프
vector<int> sAdj[MAXV + 5];
int sCost[MAXV + 5], sCostSum[MAXV + 5], indeg[MAXV + 5];
bool sIsRestaurant[MAXV + 5], sCal[MAXV + 5];

int dfs(int v);
int topological_sort();

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(label, -1, sizeof(label));

	int M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}

	for (int v = 1; v <= N; v++)
		cin >> cost[v];

	int P;
	cin >> st >> P;

	for (int i = 0; i < P; i++) {
		int x; cin >> x;
		isRestaurant[x] = true;
	}

	//scc 구하기: dfs 스패닝 트리
	for (int v = 1; v <= N; v++)
		if (label[v] == -1) dfs(v);

	//scc 그래프 구하기
	for (int v = 1; v <= N; v++) {
		int sV = SCCnum[v];
		sCost[sV] += cost[v];
		for (int next : adj[v]) {
			int sNext = SCCnum[next];
			if (sV == sNext) continue;
			sAdj[sV].push_back(sNext);
			indeg[sNext]++;
		}

		if (isRestaurant[v])
			sIsRestaurant[sV] = true;
	}

	//위상 정렬
	int ans = topological_sort();

	cout << ans;

	return 0;
}

int dfs(int v) {
	label[v] = lCnt++;
	S.push(v);

	int ret = label[v];
	for (int next : adj[v]) {
		if (label[next] == -1) ret = min(ret, dfs((next)));
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

int topological_sort() {
	sCostSum[SCCnum[st]] = sCost[SCCnum[st]];
	sCal[SCCnum[st]] = true;

	queue<int> q;

	for (int v = 0; v <= SCCcnt - 1; v++)
		if (indeg[v] == 0) q.push(v);

	while (!q.empty()) {
		int n = q.front();
		q.pop();

		for (int next : sAdj[n]) {
			if (sCal[n]) {
				sCostSum[next] = max(sCostSum[next], sCostSum[n] + sCost[next]);
				sCal[next] = true;
			}
			if (--indeg[next] == 0) q.push(next);
		}
	}

	int ret = -1;
	for (int v = 0; v <= SCCcnt - 1; v++)
		if (sCal[v] && sIsRestaurant[v]) ret = max(ret, sCostSum[v]);
	
	return ret;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 강한 연결 요소
결정적 깨달음		: DAG일 때 최단/최장거리를 구하는 것은 O(|V| + |E|)에 가능.
시간복잡도		: O(|V| + |E|)
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////