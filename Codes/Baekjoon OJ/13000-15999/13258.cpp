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
문제 해법		: 확률과 통계
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 
				  2. 
*///////////////////////////////////////////////////////////////////////