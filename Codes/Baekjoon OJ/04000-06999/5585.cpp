#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int sam;
	scanf("%d", &sam);

	int n = 1000 - sam;

	int ans = 0;
	while (n >= 500) n -= 500, ans++;
	while (n >= 100) n -= 100, ans++;
	while (n >= 50) n -= 50, ans++;
	while (n >= 10) n -= 10, ans++;
	while (n >= 5) n -= 5, ans++;
	while (n >= 1) n -= 1, ans++;

	printf("%d", ans);

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