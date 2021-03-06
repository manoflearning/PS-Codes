#include <iostream>
#include <vector>
using namespace std;

int n;
vector< vector<int> > board;
vector< vector<long long int> > dp;

int main() {
	scanf("%d", &n);

	board.resize(n, vector<int>(n));
	dp.resize(n, vector<long long int>(n));

	for (int i = 0; i < n; i++)
		for (int l = 0; l < n; l++) {
			scanf("%d", &board[i][l]);
		}

	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int l = 0; l < n; l++) {
			if (board[i][l] == 0) continue;

			int down = board[i][l] + i;
			int right = board[i][l] + l;

			if (down < n) dp[down][l] += dp[i][l];
			if (right < n) dp[i][right] += dp[i][l];
		}
	}

	printf("%lld", dp[n - 1][n - 1]);

	return 0;
}

/*
문제 해법		: 동적 프로그래밍(bottom up)
접근 방식		:
결정적 깨달음	:
오답 원인		: 1. 오버플로우
				  2.
*/
////////////////////////////////////////////////////////////////////////////////
