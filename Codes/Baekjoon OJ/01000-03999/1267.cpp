#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int Yprice = 0, Mprice = 0;

	for (int i = 0; i < n; i++) {
		int sam;
		scanf("%d", &sam);

		Yprice += (sam / 30 + 1) * 10;
		Mprice += (sam / 60 + 1) * 15;
	}

	if (Yprice < Mprice) printf("Y %d", Yprice);
	else if (Yprice > Mprice) printf("M %d", Mprice);
	else printf("Y M %d", Yprice);

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