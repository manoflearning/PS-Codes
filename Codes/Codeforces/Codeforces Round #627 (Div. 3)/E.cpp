#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

int N, H, L, R;
int arr[2005], dp[2005][2005];

int max_cnt(int loc, int t);
inline int time(int t, int plus);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(dp, -1, sizeof(dp));
	
	cin >> N >> H >> L >> R;
	
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	cout << max(max_cnt(1, arr[1]), max_cnt(1, arr[1] - 1));

	return 0;
}

int max_cnt(int loc, int t) {
	int& ret = dp[loc][t];
	//memoization
	if (ret != -1) return ret;
	
	ret = 0;
	if (L <= t && t <= R) ret++;
	
	//base case
	if (loc == N) return ret;
	
	int plus = 0;
	plus = max(plus, max_cnt(loc + 1, time(t, arr[loc + 1])));
	plus = max(plus, max_cnt(loc + 1, time(t, arr[loc + 1] - 1)));

	return ret += plus;
}

inline int time(int t, int plus) {
	return (t + plus) % H;
}