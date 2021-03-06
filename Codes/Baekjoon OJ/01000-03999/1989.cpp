#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

const int MAX = 100000;

ll N, A[MAX + 5], ans;
int aL, aR;

ll find_max(int L, int R);
void find_ans(int L, int R);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> A[i];

	ans = find_max(1, N);

	cout << ans << '\n';

	find_ans(1, N);

	cout << aL << ' ' << aR;
	
	return 0;
}

ll find_max(int L, int R) {
	//base case
	if (L == R) return A[L] * A[L];
	if (L > R) return 0;

	int mid = (L + R) / 2;

	ll ret = max(find_max(L, mid - 1), find_max(mid + 1, R));

	int mL = mid, mR = mid;
	ll sum = A[mid], mul = A[mid];

	ret = max(ret, sum * mul);
	while (!(mL == L && mR == R)) {
		if (mL == L || (mR != R && A[mL - 1] <= A[mR + 1])) {
			mR++;
			sum += A[mR];
			mul = min(mul, A[mR]);
		}
		else {
			mL--;
			sum += A[mL];
			mul = min(mul, A[mL]);
		}

		ret = max(ret, sum * mul);
	}

	return ret;
}
void find_ans(int L, int R) {
	//base case
	if (L == R) {
		if (ans == A[L] * A[L])
			aL = aR = L;
		return;
	}
	if (L > R) return;

	int mid = (L + R) / 2;

	ll ret = 0;

	int mL = mid, mR = mid;
	ll sum = A[mid], mul = A[mid];

	ret = max(ret, sum * mul);
	if (ret == ans) {
		aL = aR = mid;
		return;
	}

	while (!(mL == L && mR == R)) {
		if (mL == L || (mR != R && A[mL - 1] <= A[mR + 1])) {
			mR++;
			sum += A[mR];
			mul = min(mul, A[mR]);
		}
		else {
			mL--;
			sum += A[mL];
			mul = min(mul, A[mL]);
		}

		if (ret < sum * mul) {
			ret = sum * mul;
			if (ret == ans) {
				aL = mL, aR = mR;
				return;
			}
		}
	}
	//ans값을 발견하지 못했을 때
	find_ans(L, mid - 1);
	find_ans(mid + 1, R);
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 분할정복
결정적 깨달음		: find_max 함수와 유사한 find_ans 함수를 만들어 ans 값을 추적한다.
시간복잡도		: O(nlgn)
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////