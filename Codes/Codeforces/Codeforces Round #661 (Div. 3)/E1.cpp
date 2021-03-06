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
const int MAXn = 1e5;

struct vidx {
	int v, idx;
};

int n;
ll S;
vector<vidx> adj[MAXn + 5];
ll w[MAXn + 5], cnt[MAXn + 5];
ll nowS;

struct cmp {
	bool operator()(int a, int b) {
		return cnt[a] * (w[a] - w[a] / 2) < cnt[b] * (w[b] - w[b] / 2);
		//return w[a] * cnt[a] < w[b] * cnt[b];
	}
};

priority_queue<int, vector<int>, cmp> pq;

void init() {
	for (int i = 0; i <= n; i++) {
		adj[i].clear();
		w[i] = cnt[i] = 0;
	}
	n = S = nowS = 0;
	while (!pq.empty()) pq.pop();
}

ll dfs(int now, int prv, int idx) {
	ll& ret = cnt[idx];
	for (auto& i : adj[now]) {
		if (i.v == prv) continue;
		ret += dfs(i.v, now, i.idx);
	}
	if (ret == 0) ret = 1;
	nowS += ret * w[idx];
	return ret;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int tc; cin >> tc;
	while (tc--) {
		cin >> n >> S;

		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v >> w[i];
			adj[u].push_back({ v, i });
			adj[v].push_back({ u, i });
		}

		dfs(1, 0, n);
		
		for (int i = 0; i < n - 1; i++) pq.push(i);

		int res = 0;
		while (nowS > S) {
			res++;

			int val = pq.top();
			pq.pop();

			nowS -= cnt[val] * (w[val] - w[val] / 2);
			w[val] /= 2;

			pq.push(val);
		}

		cout << res << '\n';

		init();
	}

	return 0;
}