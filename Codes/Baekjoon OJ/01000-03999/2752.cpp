#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);

	printf("%d %d %d", a, b, c);

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