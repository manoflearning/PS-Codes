#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int num[3];
	scanf("%d %d %d", &num[0], &num[1], &num[2]);

	sort(num, num + 3);

	char ABC[4];
	scanf("%s", ABC);

	for (int i = 0; i < 3; i++)
		printf("%d ", num[ABC[i] - 'A']);

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