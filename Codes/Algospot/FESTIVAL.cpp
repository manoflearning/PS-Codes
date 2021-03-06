#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int c;
	scanf("%d", &c);

	for (int test = 0; test < c; test++) {
		int n, k;
		scanf("%d %d", &n, &k);

		vector<int> arr(n);

		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);

		double ans = 101;

		for (int i = k; i <= n; i++) {
			double sum = 0;
			
			for (int l = i - k; l < i; l++)
				sum += arr[l];

			ans = min(ans, sum / k);
			for (int l = i; l < n; l++) {
				sum += arr[l];

				ans = min(ans, sum / ((double)k + l - i + 1));
			}
		}

		printf("%.12lf\n", ans);
	}

	return 0;
}
/*
문제 해법		: 완전 탐색
접근 방식		:
결정적 깨달음		:
오답 원인		: 1. 
				  2.
*/
//////////////////////////////////////////////////////////////////////
