#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };
const long double PI = 3.141592653589793238462643383279502884197;

int N, K;
vector<ll> arr, pos, neg;

ll cal();
ll cal2();

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	
	arr.resize(N);

	bool allNeg = true;
	for (auto& i : arr) {
		cin >> i;
		if (i >= 0) {
			allNeg = false;
			pos.push_back(i);
		}
		else neg.push_back(i);
	}

	sort(arr.rbegin(), arr.rend());
	sort(pos.rbegin(), pos.rend());
	sort(neg.begin(), neg.end());

	//예외 케이스 1 : K = N
	if (K == N) {
		cout << cal();
		return 0;
	}

	//예외 케이스2 : 모든 A_i가 음수고, K가 홀수
	if (allNeg && (K & 1)) {
		cout << cal();
		return 0;
	}

	//그 외엔 언제나 product의 최댓값이 음이 아닌 정수다
	cout << cal2();

	return 0;
}

ll cal() {
	ll ret = 1;
	for (int i = 0; i < K; i++) {
		ret = ret * arr[i] % MOD;
	}
	if (ret < 0) ret += MOD;
	return ret;
}

ll cal2() {
	ll ret = 1;

	int L = -1, R = -1;
	while (L + R + 2 <= K - 2) {
		if (L + 1 >= pos.size()) {
			ret = ret * neg[R + 1] % MOD;
			ret = ret * neg[R + 2] % MOD;
			R += 2;
		}
		else if (R + 2 >= neg.size()) {
			ret = ret * pos[L + 1] % MOD;
			L += 1;
		}
		else if (neg[R + 1] * neg[R + 2] > pos[L + 1] * pos[L + 2]) {
			ret = ret * neg[R + 1] % MOD;
			ret = ret * neg[R + 2] % MOD;
			R += 2;
		}
		else {
			ret = ret * pos[L + 1] % MOD;
			L += 1;
		}
	}
	
	if (L + R + 2 == K - 1) ret = ret * pos[L + 1] % MOD;

	if (ret < 0) ret += MOD;

	return ret;
}
