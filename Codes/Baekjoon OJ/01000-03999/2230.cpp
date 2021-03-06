#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll arr[(int)1e5];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	int L = 0;
	ll ans = 1e12;
	for (int i = 1; i < n; i++) {
		while (arr[i] - arr[L] >= m && L < i) {
			ans = min(ans, arr[i] - arr[L]);
			L++;
		}
	}

	cout << ans;

	return 0;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 투 포인터 응용
결정적 깨달음		: 
시간복잡도		: O(n)
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////