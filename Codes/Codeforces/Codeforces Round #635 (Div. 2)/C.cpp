#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAXV = 2 * 1e5;

vector<int> adj[MAXV + 5], dsort;
int depth[MAXV + 5], child[MAXV + 5];

int dfs(int now, int prv = 0);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N - 1; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	//
	dfs(1);

	for (int i = 1; i <= N; i++) {
		dsort.push_back((depth[i] - 1) - (child[i] - 1));
	}

	sort(dsort.begin(), dsort.end());

	//
	ll ans = 0;

	while (K > 0) {
		ans += dsort.back();
		dsort.pop_back();
		K--;
	}
	
	cout << ans << endl;

	return 0;
}

int dfs(int now, int prv) {
	depth[now] = depth[prv] + 1;

	child[now] = 1;
	for (int next : adj[now]) {
		if (next == prv) continue;
		child[now] += dfs(next, now);
	}

	return child[now];
}