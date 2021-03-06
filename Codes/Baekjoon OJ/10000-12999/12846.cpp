#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

const int MAX = 1e5;

ll N, arr[MAX + 5];

ll find_max(int L, int R);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	cout << find_max(1, N);

	return 0;
}

ll find_max(int L, int R) {
	//base case
	if (L == R) return arr[L];
	if (L > R) return 0;

	int mid = (L + R) / 2;

	ll ret = max(find_max(L, mid - 1), find_max(mid + 1, R));

	int mL = mid, mR = mid;

	ll mul = arr[mid];

	ret = max(ret, (mR - mL + 1) * mul);
	while (!(mL == L && mR == R)) {
		if (mL == L) {
			mR++;
			mul = min(mul, arr[mR]);
		}
		else if (mR == R) {
			mL--;
			mul = min(mul, arr[mL]);
		}
		else if (arr[mL - 1] <= arr[mR + 1]) {
			mR++;
			mul = min(mul, arr[mR]);
		}
		else {
			mL--;
			mul = min(mul, arr[mL]);
		}

		ret = max(ret, (mR - mL + 1) * mul);
	}

	return ret;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 분할 정복
결정적 깨달음		: 
시간복잡도		: 
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////