#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char n[5];
	scanf("%s", n);

	if (strlen(n) == 4) printf("20");
	else if (strlen(n) == 3) {
		if (n[1] == '0') printf("%d", (n[0] - '0') * 10 + n[2] - '0');
		else printf("%d", n[0] - '0' + (n[1] - '0') * 10);
	}
	else printf("%d", n[0] - '0' + n[1] - '0');

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