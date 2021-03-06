#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

const int MAXV = 1e5;

int N, M;
vector<int> adj[MAXV + 5];
int label[MAXV + 5], labelCnt, SCCnum[MAXV + 5], SCCcnt;
stack<int> S;
vector<vector<int>> SCC;
bool finished[MAXV + 5];

void getSCC();
int dfs(int v);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

    getSCC();

    vector<int> indeg(SCCcnt);
    for (int u = 0; u < N; u++) {
        for (int v : adj[u])
            if (SCCnum[u] != SCCnum[v]) indeg[SCCnum[v]]++;
    }

    int ans = 0;
    for (int i = 0; i < SCCcnt; i++)
        if (indeg[i] == 0) ans++;
    cout << ans << '\n';

	return 0;
}

void getSCC() {
	memset(label, -1, sizeof(label));

	for (int v = 0; v < N; v++)
		if (label[v] == -1) dfs(v);
}

int dfs(int v) {
    label[v] = labelCnt++;
    S.push(v);

    int ret = label[v];
    for (int next : adj[v]) {
        //방문하지 않은 정점
        if (label[next] == -1) ret = min(ret, dfs(next));
        //방문은 했으나 아직 SCC로 분류되지 않은 정점
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