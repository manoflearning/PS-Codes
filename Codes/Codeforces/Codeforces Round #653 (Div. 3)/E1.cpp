#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vd vector<double>
#define vc vector<char>
#define vs vector<string>
#define vpi vector<pii>
#define vpl vector<pll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vvd vector<vector<double>>
#define vvc vector<vector<char>>
#define vvs vector<vector<string>>
#define vvpi vector<vector<pii>>
#define vvpl vector<vector<pll>>

const int INF = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };
const long double PI = 3.141592653589793238462643383279502884197;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	int likeA = 0, likeB = 0;

	vector<int> both, forA, forB;
	for (int i = 0; i < n; i++) {
		int t, a, b;
		cin >> t >> a >> b;
		likeA += a, likeB += b;

		if (a && b) both.push_back(t);
		else if (a) forA.push_back(t);
		else if (b) forB.push_back(t);
	}

	if (likeA < k || likeB < k) {
		cout << -1 << '\n';
		return 0;
	}

	//sort(both.begin(), both.end());
	sort(forA.rbegin(), forA.rend());
	sort(forB.rbegin(), forB.rend());

	while (!forA.empty() && !forB.empty()) {
		both.push_back(forA.back() + forB.back());
		forA.pop_back();
		forB.pop_back();
	}
	
	sort(both.begin(), both.end());

	int cnt = 0, sum = 0;
	for (auto& x : both) {
		cnt++;
		sum += x;

		if (cnt == k) break;
	}

	cout << sum << '\n';

	return 0;
}