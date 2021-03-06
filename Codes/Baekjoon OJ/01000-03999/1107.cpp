#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
vector<bool> broken(10, false);

int smallestCount();
bool brokenCheck(int number);
int digitCount(int number);

int main() {
	//input
	scanf("%d", &n);
	
	int m;
	scanf("%d", &m);
	
	for (int i = 0; i < m; i++) {
		int sam;
		scanf("%d", &sam);
		broken[sam] = true;
	}
	
	printf("%d", min(abs(n - 100), smallestCount()));

	return 0;
}

int smallestCount() {
	int ret = INT_MAX;
	for (int i = 0; i <= 1000000; i++) {
		if (!brokenCheck(i)) continue;

		ret = min(ret, abs(n - i) + digitCount(i));
	}

	return ret;
}
bool brokenCheck(int number) {
	if (number == 0)
		if (broken[number]) return false;
		else return true;

	for (int i = 0; pow(10, i) <= number; i++)
		if (broken[number % (int)pow(10, i + 1) / (int)pow(10, i)]) return false;
	
	return true;
}
int digitCount(int number) {
	if (number == 0) return 1;
	
	int count;
	for (count = 0; pow(10, count) <= number; count++);
	return count;
}

/*
문제 해법		: 완전 탐색
접근 방식		:
결정적 깨달음	:
오답 원인		: 1. 예외 처리 부족
				  2.
*/
