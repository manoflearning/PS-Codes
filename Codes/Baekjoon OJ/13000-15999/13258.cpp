#include <iostream>
using namespace std;

const int MAX = 50;

int main() {
	int n;
	cin >> n;

	double kangho;
	cin >> kangho;

	double all = kangho;
	for (int i = 1; i < n; i++) {
		int plus;
		cin >> plus;

		all += plus;
	}
	
	int j, c;
	cin >> j >> c;

	printf("%.9lf", kangho + kangho / all * j * c);

	return 0;
}
/*//////////////////////////////////////////////////////////////////////
���� �ع�		: Ȯ���� ���
���� ���		: 
������ ������		: 
���� ����		: 1. 
				  2. 
*///////////////////////////////////////////////////////////////////////