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
const int MAXN = 1e5;

int N;
ll a[MAXN + 5], t[MAXN + 5];
vector<int> b;

bool cmp(int x, int y) {
	if (a[x] != a[y]) return a[x] < a[y];
	return x < y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) { 
		cin >> a[i] >> t[i];
		b.push_back(i);
	}

	sort(b.begin(), b.end(), cmp);

	ll res = -1, now = 0;
	for (int l = 0; l < b.size(); ) {
		priority_queue<int, vector<int>, greater<int>> pq;
		pq.push(b[l++]);
		
		while (true) {
			now = max(now + t[pq.top()], a[pq.top()] + t[pq.top()]);
			//cout << pq.top() << ' ' << now << '\n';
			pq.pop();

			while (l < b.size() && a[b[l]] <= now) pq.push(b[l++]);

			if (pq.empty()) break;

			res = max(res, now - a[pq.top()]);
		}
	}

	cout << res;

	return 0;
}