#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	double flag = (double)(a * a) / (b * b + c * c);

	int b_ans, c_ans;
	for (b_ans = 1; b_ans * b_ans <= flag * b * b; b_ans++); b_ans--;
	for (c_ans = 1; c_ans * c_ans <= flag * c * c; c_ans++); c_ans--;

	printf("%d %d", b_ans, c_ans);

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