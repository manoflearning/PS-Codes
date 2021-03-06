#include <iostream>
#include <vector>
#define ll long long
using namespace std;

const int MAX = 4000000;

vector<int> sosu;
bool visited[MAX + 5];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n; cin >> n;

	//에라토스테네스의 체
	sosu.push_back(2);
	for (int i = 4; i <= n; i += 2)
		visited[i] = true;
	for (ll i = 3; i <= n; i += 2) {
		if (visited[i]) continue;
		sosu.push_back(i);
		for (ll l = i * i; l <= n; l += 2 * i) {
			visited[l] = true;
		}
	}

	//투 포인터
	ll sum = 0;
	int L = 0, ans = 0;
	for (int i = 0; i < sosu.size(); i++) {
		sum += sosu[i];
		while (sum > n && L < i) {
			sum -= sosu[L];
			L++;
		}

		if (sum == n) ans++;
	}

	cout << ans;

	return 0;
}