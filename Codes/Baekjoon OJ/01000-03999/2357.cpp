#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct sgt {
	int min;
	int max;
};

int arr[100000];
vector<sgt> sgtr;

int MIN(int L, int R, int n, int nL, int nR);
int MAX(int L, int R, int n, int nL, int nR);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	//
	int flag;
	for (flag = 1; flag < n; flag *= 2);

	sgtr.resize(flag * 2);
	//make segment tree
	for (int i = flag; i < flag + n; i++)
		sgtr[i].min = arr[i - flag], sgtr[i].max = arr[i - flag];
	for (int i = flag - 1; i >= 1; i--) {
		sgtr[i].min = min(sgtr[2 * i].min, sgtr[2 * i + 1].min);
		sgtr[i].max = max(sgtr[2 * i].max, sgtr[2 * i + 1].max);
	}
	//
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		cout << MIN(a, b, 1, 1, flag) << ' ' << MAX(a, b, 1, 1, flag) << '\n';
	}

	return 0;
}

int MIN(int L, int R, int n, int nL, int nR) {
	if (R < nL || nR < L) return 1000000001;
	if (L <= nL && nR <= R) return sgtr[n].min;
	
	int mid = (nL + nR) / 2;
	return min(MIN(L, R, 2 * n, nL, mid), MIN(L, R, 2 * n + 1, mid + 1, nR));
}
int MAX(int L, int R, int n, int nL, int nR) {
	if (R < nL || nR < L) return 0;
	if (L <= nL && nR <= R) return sgtr[n].max;

	int mid = (nL + nR) / 2;
	return max(MAX(L, R, 2 * n, nL, mid), MAX(L, R, 2 * n + 1, mid + 1, nR));
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 세그트리
접근 방식		: 완전 탐색을 이용하면 O(n * m)의 시간복잡도. 세그트리를 이용하면, O(lgn * m)의 시간복잡도.
결정적 깨달음		: 
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////