#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 2 * 1e5;

int N, C, arr[MAX + 5], ans;

void find_max(int L, int R);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> C;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	sort(arr + 1, arr + N + 1);

	find_max(1, arr[N] - arr[1]);

	cout << ans;

	return 0;
}

void find_max(int L, int R) {
	//base case
	if (L > R) return;

	int mid = (L + R) / 2;

	int wifi = arr[1], cnt = 1;
	for (int i = 2; i <= N; i++) {
		int d = arr[i] - wifi;
		if (d >= mid) {
			cnt++;
			wifi = arr[i];
		}
	}

	if (cnt >= C) ans = max(ans, mid);
	
	if (cnt >= C) find_max(mid + 1, R);
	else find_max(L, mid - 1);
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 이분 탐색
결정적 깨달음		: 
시간복잡도		: O(nlgn)
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////