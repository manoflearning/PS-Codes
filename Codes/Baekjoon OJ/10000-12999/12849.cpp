#include <iostream>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;

ll dp[(int)1e5 + 5][8];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	/*
	0 정보과학관
	1 전산관
	2 미래관
	3 신양관
	4 한경직기념관
	5 진리관
	6 학생회관
	7 형남공학관
	*/

	int D; cin >> D;

	dp[0][0] = 1;
	
	for (int i = 1; i <= D; i++) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2] + dp[i - 1][3]) % MOD;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][4]) % MOD;
		dp[i][3] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][5]) % MOD;
		dp[i][4] = (dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][7]) % MOD;
		dp[i][5] = (dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][6]) % MOD;
		dp[i][6] = (dp[i - 1][5] + dp[i - 1][7]) % MOD;
		dp[i][7] = (dp[i - 1][4] + dp[i - 1][6]) % MOD;
	}

	cout << dp[D][0];

	return 0;
}