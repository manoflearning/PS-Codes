#include <iostream>
using namespace std;

int main() {
	int sum[5] = { 0, };

	for (int i = 0; i < 5; i++) {
		for (int l = 0; l < 4; l++) {
			int sam;
			scanf("%d", &sam);

			sum[i] += sam;
		}
	}

	int flag = 0;

	for (int i = 1; i < 5; i++)
		if (sum[flag] < sum[i]) flag = i;

	printf("%d %d", flag + 1, sum[flag]);

	return 0;
}
/*
문제 해법		: 
접근 방식		:
결정적 깨달음		:
오답 원인		: 1. 
				  2.
*/
//////////////////////////////////////////////////////////////////////