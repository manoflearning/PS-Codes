#include <iostream>
#include <vector>
using namespace std;

int n, m;

vector< vector<int> > dp;

int main() {
	scanf("%d %d", &n, &m);

	dp.resize(m, vector<int>(n));

	for (int i = 0; i < m; i++)
		dp[i][0] = 1;
	for (int i = 0; i < n; i++)
		dp[0][i] = 1;

	for (int y = 1; y < m; y++) {
		for (int x = 1; x < n; x++) {
			dp[y][x] = ((long long int)dp[y - 1][x - 1] + dp[y - 1][x] + dp[y][x - 1]) % 1000000007;
		}
	}

	printf("%d", dp[m - 1][n - 1]);

	return 0;
}
/*
문제 해법		: 동적 계획법(bottom up)
접근 방식		: 
결정적 깨달음	: 
오답 원인		: 1. 
				  2. 
*/
//////////////////////////////////////////////////////////////////////