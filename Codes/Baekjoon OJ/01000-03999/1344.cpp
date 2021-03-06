#include <iostream>
#include <cstring>
using namespace std;

int decimal[7] = { 2, 3, 5, 7, 11, 13, 17 };

double dp[19][20];

double calculate(int goal, int time, int percent);

int main() {
	for (int i = 0; i < 19; i++)
		for (int l = 0; l < 20; l++) {
			dp[i][l] = -1;
		}

	int a, b;
	cin >> a >> b;

	double per_a = calculate(0, 1, a);
	for (int i = 0; i < 19; i++)
		for (int l = 0; l < 20; l++) {
			dp[i][l] = -1;
		}
	double per_b = calculate(0, 1, b);

	printf("%.6lf", 1 - per_a * per_b);

	return 0;
}

double calculate(int goal, int time, int percent) {
	double& ret = dp[goal][time];
	//memoization
	if (ret != -1) return ret;
	//base case
	if (time == 19) {
		bool check = true;
		for (int i = 0; i < 7; i++)
			if (goal == decimal[i]) {
				check = false;
				break;
			}

		if (check) return ret = 1;
		else return ret = 0;
	}

	ret = 0;
	
	for (int i = 1; i <= percent; i++)
		ret += calculate(goal + 1, time + 1, percent);
	for (int i = percent + 1; i <= 100; i++)
		ret += calculate(goal, time + 1, percent);

	ret /= 100;

	return ret;
}
/*//////////////////////////////////////////////////////////////////////
문제 해법		: 동적계획법, 확률
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 두 개의 독립된 연산을 하나의 dp 배열로 처리함
				  2. 
*///////////////////////////////////////////////////////////////////////