#include <iostream>
using namespace std;

int main() {
	while (true) {
		int n;
		scanf("%d", &n);

		if (n == 0) break;

		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += (n - i) * (n - i);

		printf("%d\n", sum);
	}

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