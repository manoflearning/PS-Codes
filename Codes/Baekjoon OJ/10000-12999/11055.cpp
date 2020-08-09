#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> A;
vector<int> dp;

int longest(int flag);

int main() {
	scanf("%d", &n);

	A.resize(n);
	dp.resize(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);

	int ret = 0;
	for (int i = 0; i < n; i++)
		ret = max(ret, longest(i));

	printf("%d", ret);

	return 0;
}

int longest(int flag) {
	//memoization
	if (dp[flag] != 0) return dp[flag];
	//
	for (int i = flag + 1; i < n; i++) {
		if (A[i] > A[flag]) {
			dp[flag] = max(dp[flag], longest(i));
		}
	}
	dp[flag] += A[flag];

	return dp[flag];
}

/*
���� �ع�		: ���� ���α׷���
���� ���		:
������ ������	:
���� ����		: 1. 
				  2.
*/