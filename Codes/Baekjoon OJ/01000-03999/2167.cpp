/*
문제 해법		: 동적 프로그래밍
접근 방식		: 
결정적 깨달음	: 다른 방식의 메모이제이션 활용
오답 원인		: 1. 
				  2.
*/

#include <iostream>
#include <cstdio>

using namespace std;

int n, m;
int arr[300][300];
int x_s, y_s, x_e, y_e;

int dp[300][300];

void dpMake();

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++)
		for (int l = 0; l < m; l++) {
			scanf("%d", &arr[i][l]);

			dp[i][l] = arr[i][l];
		}

	dpMake();

	int k;
	scanf("%d", &k);

	for (int test = 0; test < k; test++) {
		scanf("%d %d %d %d", &y_s, &x_s, &y_e, &x_e);

		x_s--, y_s--, x_e--, y_e--;

		int res = dp[y_e][x_e];

		if(y_s - 1 >= 0 && x_s - 1 >= 0) res += - dp[y_s - 1][x_e] - dp[y_e][x_s - 1] + dp[y_s - 1][x_s - 1];
		else if (y_s - 1 >= 0) res += - dp[y_s - 1][x_e];
		else if (x_s - 1 >= 0) res += - dp[y_e][x_s - 1];

		printf("%d\n", res);
	}

	return 0;
}

void dpMake() {
	for (int i = 1; i < m; i++)
		dp[0][i] += dp[0][i - 1];
	for (int i = 1; i < n; i++)
		dp[i][0] += dp[i - 1][0];

	for (int i = 1; i < n; i++)
		for (int l = 1; l < m; l++) {
			dp[i][l] += dp[i - 1][l] + dp[i][l - 1] - dp[i - 1][l - 1];
		}
}
