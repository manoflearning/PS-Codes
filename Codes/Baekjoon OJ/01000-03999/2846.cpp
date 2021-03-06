#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int road[1000];
	int flag = 0;
	int ans = 0;

	scanf("%d", &road[0]);
	for (int i = 1; i < n; i++) {
		scanf("%d", &road[i]);

		if (road[i] > road[i - 1])
			ans = max(ans, road[i] - road[flag]);
		else flag = i;
	}

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