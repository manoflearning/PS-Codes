#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > maze;
int n, m;

vector< vector<int> > dp;

int main() {
	scanf("%d %d", &n, &m);

	maze.resize(n, vector<int>(m));
	dp.resize(n, vector<int>(m));

	for (int i = 0; i < n; i++)
		for (int l = 0; l < m; l++) {
			scanf("%d", &maze[i][l]);
		}

	dp[0][0] = maze[0][0];
	for (int i = 1; i < n; i++)
		dp[i][0] = maze[i][0] + dp[i - 1][0];
	for (int i = 1; i < m; i++)
		dp[0][i] = maze[0][i] + dp[0][i - 1];

	for (int i = 1; i < n; i++)
		for (int l = 1; l < m; l++) {
			dp[i][l] = max(dp[i][l - 1], dp[i - 1][l]);
			dp[i][l] += maze[i][l];
		}

	printf("%d", dp[n - 1][m - 1]);

	return 0;
}

/*
문제 해법		: 동적 프로그래밍
접근 방식		:
결정적 깨달음	:
오답 원인		: 1. 
				  2.
*/