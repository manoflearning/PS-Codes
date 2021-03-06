#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };
const int MAXV = 3e5;

int N;
vector<int> adj[MAXV + 5];
int par[MAXV + 5], dep[MAXV + 5];
ll dp[MAXV + 5][5];
ll cntD, cntG;

void dfs(int now, int prv);
ll dfsD(int now, int prv, int cnt);
ll dfsD2(int now, int prv);
void dfsG(int now, int prv);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);

	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <= N; i++) {
		cntD += dfsD(i, par[i], 4);
		cntD += dfsD2(i, par[i]);
	}
	
	dfsG(1, 0);

	//cout << cntD << ' ' << cntG << '\n';

	if (cntD > 3 * cntG) cout << "D";
	else if (cntD < 3 * cntG) cout << "G";
	else if (cntD == 3 * cntG) cout << "DUDUDUNGA";

	return 0;
}

void dfs(int now, int prv) {
	par[now] = prv;
	dep[now] = dep[prv] + 1;
	for (int i : adj[now]) {
		if (i == prv) continue;
		dfs(i, now);
	}
}

ll dfsD(int now, int prv, int cnt) {
	ll& ret = dp[now][cnt];
	if (ret != -1) return ret;
	if (cnt == 0) return ret = 0;

	ret = 0;

	if (cnt == 1) ret = 1;
	for (int i : adj[now]) {
		if (i == prv) continue;
		ret += dfsD(i, now, cnt - 1);
	}
	return ret;
}

ll dfsD2(int now, int prv) {
	ll ret = 0, cnt1 = 0;
	for (int i : adj[now]) {
		if (i == prv) continue;
		cnt1 += dfsD(i, now, 1);
	}
	for (int i : adj[now]) {
		if (i == prv) continue;
		ret += (cnt1 - 1) * dfsD(i, now, 2);
	}
	return ret;
}

void dfsG(int now, int prv) {
	if (adj[now].size() >= 3) {
		ll n = adj[now].size();
		cntG += n * (n - 1) * (n - 2) / 6;
	}
	for (int i : adj[now]) {
		if (i == prv) continue;
		dfsG(i, now);
	}
}