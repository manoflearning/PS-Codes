#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector< vector<int> > dp;

int main() {
	scanf("%d", &n);

	dp.resize(n, vector<int>(10, 1));
	dp[0][0] = 0;

	for (int i = 1; i < n; i++) {
		dp[i][0] *= dp[i - 1][1] % 1000000000;
		for (int l = 1; l <= 8; l++) {
			dp[i][l] *= (dp[i - 1][l - 1] + dp[i - 1][l + 1]) % 1000000000;
		}
		dp[i][9] *= dp[i - 1][8] % 1000000000;
	}

	long long int sum = 0;
	for (int i = 0; i < 10; i++)
		sum += dp[n - 1][i];
	sum %= 1000000000;

	printf("%lld", sum);

	return 0;
}
/*
문제 해법		: 동적계획법(bottom up)
접근 방식		: 
결정적 깨달음	: 
오답 원인		: 1. 
				  2. 
*/
//////////////////////////////////////////////////////////////////////