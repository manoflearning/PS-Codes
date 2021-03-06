#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

const int MAX = 2 * 1e5;

ll N, a[MAX + 5], b[MAX + 5];
vector<ll> pos, mid, neg;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> a[i];
	for (int i = 1; i <= N; i++)
		cin >> b[i];

	for (int i = 1; i <= N; i++) {
		int v = a[i] - b[i];
		if (v > 0) pos.push_back(v);
		else if (v == 0) mid.push_back(v);
		else neg.push_back(-v);
	}

	sort(neg.begin(), neg.end());

	ll ans = 0;
	//양수끼리 조합
	ans += (ll)pos.size() * (pos.size() - 1) / 2;
	//양수와 0의 조합
	ans += (ll)pos.size() * mid.size();
	//양수와 음수의 조합
	for (int i = 0; i < pos.size(); i++) {
		ll f = lower_bound(neg.begin(), neg.end(), pos[i]) - neg.begin();
		ans += f;
	}

	cout << ans;

	return 0;
}