/*
문제 해법		: 완전 탐색
접근 방식		: 
결정적 깨달음	: 
오답 원인		: 1. 시간 초과
				  2.
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
vector<int> number;
int mr = INT_MAX;
vector<int> ans;

int main() {
	scanf("%d", &n);

	number.resize(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &number[i]);

	for (int i = 0; i < n; i++)
		for (int l = i + 1; l < n; l++) {
			mr = min(mr, abs(number[i] - number[l]));
		}

	int flag = 0;
	ans.resize(flag + 1);
	for (int i = mr; i >= 2; i--) {
		int r = number[0] % i;

		bool truism = true;
		for (int l = 1; l < n; l++)
			if (r != number[l] % i) {
				truism = false;
				break;
			}

		if (truism) {
			ans[flag] = i;
			flag++;
			ans.resize(flag + 1);
			break;
		}
	}

	for (int i = 2; ans[0] >= 2 * i; i++) {
		if (ans[0] % i != 0) continue;

		int cal = ans[0] / i;

		int r = number[0] % cal;

		bool truism = true;
		for (int l = 1; l < n; l++)
			if (r != number[l] % cal) {
				truism = false;
				break;
			}

		if (truism) {
			ans[flag] = cal;
			flag++;
			ans.resize(flag + 1);
		}
	}

	for (int i = flag - 1; i >= 0; i--)
		printf("%d ", ans[i]);

	return 0;
}