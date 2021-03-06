#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };
const int MAXV = 1e5;

int N, S, D;
vector<int> adj[MAXV + 5];
int mxDep[MAXV + 5];

int dfs(int now, int prv);
int dfs2(int now, int prv);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> S >> D;
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(S, 0);

	cout << 2 * dfs2(S, 0);

	return 0;
}

int dfs(int now, int prv) {
	int& ret = mxDep[now];
	for (int i : adj[now]) {
		if (i == prv) continue;
		ret = max(ret, dfs(i, now) + 1);
	}
	//cout << now << ' ' << ret << '\n';
	return ret;
}

int dfs2(int now, int prv) {
	if (mxDep[now] <= D) return 0;
	int ret = 0;
	for (int i : adj[now]) {
		if (i == prv) continue;
		if (mxDep[i] + 1 <= D) continue;
		ret += dfs2(i, now) + 1;
	}
	return ret;
}