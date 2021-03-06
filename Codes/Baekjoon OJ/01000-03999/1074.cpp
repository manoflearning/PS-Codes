#include <iostream>
#include <cmath>
using namespace std;

int n, r, c;

int Z(int flag, int y, int x);

int main() {
	scanf("%d %d %d", &n, &r, &c);

	printf("%d", Z(n, r, c));
}

int Z(int flag, int y, int x) {
	//base case
	if (flag == 1) {
		return x + 2 * y;
	}
	//
	int check = pow(2, flag - 1);

	int ans = 0;

	if (y >= check && x >= check) {
		ans += 3 * check * check;
		ans += Z(flag - 1, y - check, x - check);
	}
	else if (y >= check) {
		ans += 2 * check * check;
		ans += Z(flag - 1, y - check, x);
	}
	else if (x >= check) {
		ans += check * check;
		ans += Z(flag - 1, y, x - check);
	}
	else ans += Z(flag - 1, y, x);

	return ans;
}
/*
문제 해법		: 분할 정복
접근 방식		:
결정적 깨달음	:
오답 원인		: 1.
				  2.
*/
//////////////////////////////////////////////////////////////////////