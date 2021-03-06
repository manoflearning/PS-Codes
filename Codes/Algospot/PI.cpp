#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 10000;

char num[MAX + 1];

int dp[10000][3];

int min_memorize(int end, int size);
void difficulty_check(int& ret, int& end, int& size);

int main() {
	int t;
	scanf("%d", &t);

	for (int test = 0; test < t; test++) {
		memset(dp, -1, sizeof(dp));

		scanf("%s", num);

		int len = strlen(num);

		int ans = min(min_memorize(len - 1, 3), min_memorize(len - 1, 4));
		ans = min(ans, min_memorize(len - 1, 5));

		printf("%d\n", ans);
	}

	return 0;
}

int min_memorize(int end, int size) {
	//base case
	if (end - size < -1) return 1000000;

	int& ret = dp[end][size - 3];
	//memoization
	if (ret != -1) return ret;
	
	difficulty_check(ret, end, size);

	if (end - size == -1) return ret;

	int plus = min_memorize(end - size, 3);
	plus = min(plus, min_memorize(end - size, 4));
	plus = min(plus, min_memorize(end - size, 5));

	return ret += plus;
}
void difficulty_check(int& ret, int& end, int& size) {
	for (int i = end - size + 1; i < end; i++) {
		if (num[i] != num[i + 1]) break;
		if (i == end - 1) ret = 1;
	}
	if (ret == -1) {
		for (int i = end - size + 1; i < end; i++) {
			if (num[i] != num[i + 1] - 1) break;
			if (i == end - 1) ret = 2;
		}
	}
	if (ret == -1) {
		for (int i = end - size + 1; i < end; i++) {
			if (num[i] != num[i + 1] + 1) break;
			if (i == end - 1) ret = 2;
		}
	}
	if (ret == -1) {
		for (int i = end - size + 1; i < end - 1; i++) {
			if (num[i] != num[i + 2]) break;
			if (i == end - 2) ret = 4;
		}
	}
	if (ret == -1) {
		int check = num[end] - num[end - 1];
		for (int i = end - size + 1; i < end - 1; i++) {
			if (num[i] + check != num[i + 1]) break;
			if (i == end - 2) ret = 5;
		}
	}
	if (ret == -1) ret = 10;
}
/*
문제 해법		: 
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 
				  2. 
*/
//////////////////////////////////////////////////////////////////////
