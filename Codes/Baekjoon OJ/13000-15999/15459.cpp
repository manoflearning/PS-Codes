#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#define ll long long
using namespace std;

const int MAX = 100000;

ll n, m;
ll fl[MAX + 1], sp[MAX + 1], psum[MAX + 1];
int flag;
vector<int> sgtr;

int SPICE(int L, int R, int n, int nL, int nR);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> fl[i] >> sp[i];

		psum[i] = fl[i] + psum[i - 1];
	}
	//construct segment tree of spiciness
	for (flag = 1; flag < n; flag *= 2);
	sgtr.resize(2 * flag);
	for (int i = flag; i < flag + n; i++)
		sgtr[i] = sp[i - flag + 1];
	for (int i = flag - 1; i >= 1; i--)
		sgtr[i] = max(sgtr[2 * i], sgtr[2 * i + 1]);
	//
	int left = 1, right = 1;
	while (psum[right] - psum[left - 1] < m) right++;

	int ans = INT_MAX;
	for (; right <= n; right++) {
		while (psum[right] - psum[left - 1] >= m) left++;
		left--;
		ans = min(ans, SPICE(left, right, 1, 1, flag));
	}

	cout << ans;

	return 0;
}

int SPICE(int L, int R, int n, int nL, int nR) {
	if (R < nL || nR < L) return 0;
	if (L <= nL && nR <= R) return sgtr[n];
	int mid = (nL + nR) / 2;
	return max(SPICE(L, R, 2 * n, nL, mid), SPICE(L, R, 2 * n + 1, mid + 1, nR));
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: psum + 최댓값 세그트리
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////