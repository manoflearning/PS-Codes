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
const int MAXN = 500;

int N, f[MAXN + 5][MAXN + 5];
vector<ll> p(MAXN + 5, -1);
ll fac[MAXN + 5], w[MAXN + 5];
bool visited[MAXN + 5];
set<int> s;
set<int> adj[MAXN + 5];

ll find(int x) {
	if (p[x] < 0) return x;
	p[x] = find(p[x]);
	return p[x];
}

void merge(int a, int b) {
	ll A = find(a), B = find(b);
	if (A == B) return;
	p[A] += p[B];
	p[B] = A;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	fac[0] = fac[1] = 1;
	for (int i = 2; i <= MAXN; i++)
		fac[i] = i * fac[i - 1] % MOD;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> f[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (f[i][j] & f[j][i]) merge(i, j);
		}
	}

	for (int i = 1; i <= N; i++) s.insert(find(i));

	for (int i : s) w[i] = -p[i];

	ll res = 1;

	for (int i : s) res = res * fac[w[i] - 1] % MOD;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (f[i][j] & !f[j][i]) adj[find(i)].insert(find(j));
		}
	}

	for (int i : s) {
		if (adj[i].size() >= 2) continue;
		for (int j : adj[i]) res = res * w[j] % MOD;
		//res = res * w[ *adj[i].begin() ] % MOD;
	}

	cout << res;

	return 0;
}