#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	while (n < 2013) n += 60;

	int flag1 = (n - 2013) % 12;
	int flag2 = (n - 2013) % 10;

	if (flag1 == 0) printf("F");
	else if (flag1 == 1) printf("G");
	else if (flag1 == 2) printf("H");
	else if (flag1 == 3) printf("I");
	else if (flag1 == 4) printf("J");
	else if (flag1 == 5) printf("K");
	else if (flag1 == 6) printf("L");
	else if (flag1 == 7) printf("A");
	else if (flag1 == 8) printf("B");
	else if (flag1 == 9) printf("C");
	else if (flag1 == 10) printf("D");
	else if (flag1 == 11) printf("E");

	if (flag2 == 0) printf("9");
	else if (flag2 == 1) printf("0");
	else if (flag2 == 2) printf("1");
	else if (flag2 == 3) printf("2");
	else if (flag2 == 4) printf("3");
	else if (flag2 == 5) printf("4");
	else if (flag2 == 6) printf("5");
	else if (flag2 == 7) printf("6");
	else if (flag2 == 8) printf("7");
	else if (flag2 == 9) printf("8");
	
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