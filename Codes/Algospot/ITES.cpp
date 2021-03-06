#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

const long long CAL = pow(2, 32);

int main() {
	int t;
	scanf("%d", &t);

	for (int test = 0; test < t; test++) {
		int k, n;
		scanf("%d %d", &k, &n);
		
		queue<int> arr;
		int sum = 0, ans_count = 0;

		long long flag = 1983;
		for (int i = 1; i < n; i++) {
			arr.push(flag % 10000 + 1);
			sum += arr.back();

			while (true) {
				if (sum > k) {
					sum -= arr.front();
					arr.pop();
				}
				else if (sum == k) {
					ans_count++;
					break;
				}
				else break;
			}

			flag = (flag * 214013 + 2531011) % CAL;
		}
		
		printf("%d\n", ans_count);

		while (!arr.empty()) arr.pop();
		sum = 0, ans_count = 0;
	}

	return 0;
}
/*//////////////////////////////////////////////////////////////////////
문제 해법		: 
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 
				  2. 
*///////////////////////////////////////////////////////////////////////
