#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

const int MAX = 100;
const long long MIN = (long long)INT_MIN - 1;

int n, m;
int num1[MAX], num2[MAX];

int dp[101][101];

int JLIS(int start1, int start2);

int main() {
	int t;
	scanf("%d", &t);

	for (int test = 0; test < t; test++) {
		memset(dp, -1, sizeof(dp));

		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; i++)
			scanf("%d", &num1[i]);
		for (int i = 0; i < m; i++)
			scanf("%d", &num2[i]);

		printf("%d\n", JLIS(-1, -1) + 1);
	}

	return 0;
}

int JLIS(int start1, int start2) {
	int& ret = dp[start1 + 1][start2 + 1];
	//memoization
	if (ret != -1) return ret;

	long long check = max((start1 == -1 ? MIN : num1[start1]), (start2 == -1 ? MIN : num2[start2]));

	for (int i = start1 + 1; i < n; i++)
		if (num1[i] > check) ret = max(ret, JLIS(i, start2) + 1);
	for (int i = start2 + 1; i < m; i++)
		if (num2[i] > check) ret = max(ret, JLIS(start1, i) + 1);

	return ret;
}
/*
문제 해법		: 
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 
				  2. 
*/
//////////////////////////////////////////////////////////////////////
