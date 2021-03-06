#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

const ll MAX = 1e18;
const int digit = 61;

ll u, v;
vector<bool> odd(digit);
vector<ll> digits(digit), N(digit);
bool cannot;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> u >> v;

	if (u == 0 && v == 0) {
		cout << 0;
		return 0;
	}
	if (u > v) {
		cout << -1;
		return 0;
	}

	for (ll i = 0; i < digit; i++)
		digits[i] = ((ll)1 << i);
	//
	for (ll i = 0; i < digit; i++) {
		if (u & digits[i]) odd[i] = true;
	}

	//
	ll sum = 0;
	for (int i = 0; i < digit; i++)
		if (odd[i]) {
			sum += digits[i];
			N[i]++;
		}

	if (v < sum) { //u를 만족하는 배열이 없는 경우
		cout << -1;
		return 0;
	}

	v -= sum;
	
	//
	while (v > 0) {
		ll sum = 0;
		for (int i = digit - 1; i >= 0; i--) {
			if (v >= 2 * digits[i]) {
				v -= 2 * digits[i];
				sum += digits[i];
				N[i] += 2;
			}
		}

		if (v == 1) {
			cannot = true;
			break;
		}
	}

	//출력
	if (cannot) cout << -1;
	else {
		vector<ll> ans;
		while (true) {
			ll sum = 0;
			for (int i = digit - 1; i >= 0; i--)
				if (N[i] > 0) {
					N[i]--;
					sum += digits[i];
				}
			if (sum == 0) break;
			ans.push_back(sum);
		}
		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << ' ';
	}

	return 0;
}