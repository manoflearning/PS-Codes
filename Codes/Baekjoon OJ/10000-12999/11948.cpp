#include <iostream>
using namespace std;

int main() {
	int test1[4];
	int flag1 = 0;
	for (int i = 0; i < 4; i++) {
		scanf("%d", &test1[i]);
		
		if (test1[i] < test1[flag1]) flag1 = i;
	}

	int test2[2];
	for (int i = 0; i < 2; i++)
		scanf("%d", &test2[i]);

	int sum = 0;
	for (int i = 0; i < 4; i++)
		if (i != flag1) sum += test1[i];
	sum += test2[0] > test2[1] ? test2[0] : test2[1];

	printf("%d", sum);

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