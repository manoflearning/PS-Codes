#include <iostream>
#define ll long long
using namespace std;

const int MAX = 100000, MAXD = 29;

int student[MAX + 1];
int f[MAX + 1][MAXD + 1];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll n, k, m;
	cin >> n >> k >> m;

	for (int i = 1; i <= n; i++)
		cin >> student[i];

	for (int i = 1; i <= k; i++)
		cin >> f[i][0];

	for (int j = 1; j <= MAXD; j++) {
		for (int i = 1; i <= k; i++) {
			f[i][j] = f[f[i][j - 1]][j - 1];
		}
	}
	
	for (int i = 1; i <= n; i++) {
		ll x = m - 1;

		for (int j = MAXD; j >= 0; j--) {
			if (x >= ((ll)1 << j)) {
				x -= ((ll)1 << j);
				student[i] = f[student[i]][j];
			}
		}

		cout << student[i] << ' ';
	}

	return 0;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 희소 테이블
접근 방식		:
결정적 깨달음		:
오답 원인		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////