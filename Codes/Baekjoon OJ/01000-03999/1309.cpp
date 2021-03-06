#include <iostream>
#include <vector>
using namespace std;

enum lion {
	c1, c2, no
};

int n;

vector< vector<int> > dp;

int lion_count(int x, int flag);

int main() {
	scanf("%d", &n);

	dp.resize(n + 1, vector<int>(3, -1));

	printf("%d", (lion_count(n, lion::c1) + lion_count(n, lion::c2) + lion_count(n, lion::no)) % 9901);

	return 0;
}

int lion_count(int x, int flag) {
	//base case
	if (x == 1) return 1;
	//memoization
	if (dp[x][flag] != -1) return dp[x][flag];
	//
	dp[x][flag] = 0;

	if (flag != lion::c1) dp[x][flag] += lion_count(x - 1, lion::c1);
	if (flag != lion::c2) dp[x][flag] += lion_count(x - 1, lion::c2);
	dp[x][flag] += lion_count(x - 1, lion::no);

	dp[x][flag] %= 9901;

	return dp[x][flag];
}
/*
문제 해법		: 동적 계획법(top down)
접근 방식		: 
결정적 깨달음	: 
오답 원인		: 1. 
				  2. 
*/
//////////////////////////////////////////////////////////////////////