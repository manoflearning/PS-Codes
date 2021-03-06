#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10;

int can_make[MAX];

int common(int n);

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> can_make[i];

	sort(can_make, can_make + n);

	int flag = common(n);
	
	for (int i = 0; i < k; i++) {
		int sam;
		cin >> sam;

		if (sam % flag == 0) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}

int common(int n) {
	int ret = can_make[0];

	bool check = true;
	while (check) {
		if (360 % ret != 0) {
			ret--;
			continue;
		}
		for (int i = 0; i < n; i++) {
			if (can_make[i] % ret != 0) {
				ret--;
				break;
			}
			if (i == n - 1) check = false;
		}
	}
	
	return ret;
}
/*//////////////////////////////////////////////////////////////////////
문제 해법		: 정수론
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 
				  2. 
*///////////////////////////////////////////////////////////////////////