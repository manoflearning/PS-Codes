#include <iostream>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	char bread[10][10];
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++) {
			scanf(" %c", &bread[y][x]);
		}

	for (int y = 0; y < n; y++) {
		for (int x = m - 1; x >= 0; x--)
			printf("%c", bread[y][x]);
		
		printf("\n");
	}

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