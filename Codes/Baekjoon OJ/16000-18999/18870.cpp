#include <iostream>
#include <algorithm>
#define pii pair<int, int>
using namespace std;

const int MAX = 1e6;

int arr[MAX + 5];
pii arr2[MAX + 5];
int ans[MAX + 5];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		arr2[i].first = arr[i], arr2[i].second = i;
	}

	sort(arr2, arr2 + N);

	int cnt = 0;
	ans[arr2[0].second] = cnt;
	for (int i = 1; i < N; i++) {
		if (arr2[i - 1].first < arr2[i].first) cnt++;
		ans[arr2[i].second] = cnt;
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}

	return 0;
}
/*//////////////////////////////////////////////////////////////////
문제 해법		: 정렬
결정적 깨달음		:
시간복잡도		: O(nlgn)
오답 원인		: 1.
				  2.
*///////////////////////////////////////////////////////////////////