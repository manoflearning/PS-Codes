#include <iostream>
using namespace std;

int main() {
	int sum1 = 0, sum2 = 0;

	for (int i = 3; i >= 1; i--) {
		int sam;
		scanf("%d", &sam);

		sum1 += i * sam;
	}

	for (int i = 3; i >= 1; i--) {
		int sam;
		scanf("%d", &sam);

		sum2 += i * sam;
	}

	if (sum1 > sum2) printf("A");
	else if (sum1 < sum2) printf("B");
	else printf("T");

	return 0;
}
/*
���� �ع�		: 
���� ���		:
������ ������		:
���� ����		: 1. 
				  2.
*/
//////////////////////////////////////////////////////////////////////