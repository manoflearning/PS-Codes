#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	long long sum = 0;
	for (int flag = 1; flag * flag <= n; flag++) sum += n / flag - (flag - 1);

	printf("%lld", sum);

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