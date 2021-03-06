#include <iostream>
#include <cmath>
using namespace std;

int n;

void hanoi(int count, char from, char tmp, char to);
int hanoi_count(int x);

int main() {
	scanf("%d", &n);
	
	printf("%d\n", hanoi_count(n));

	hanoi(n, '1', '2', '3');
}

void hanoi(int count, char from, char tmp, char to) {
	//base case
	if (count == 1) {
		printf("%c %c\n", from, to);
		return;
	}
	//
	hanoi(count - 1, from, to, tmp);
	printf("%c %c\n", from, to);
	hanoi(count - 1, tmp, from, to);
}
int hanoi_count(int x) {
	int count = 0;
	for (int i = 0; i < x; i++) {
		count += pow(2, i);
	}

	return count;
}
/*
문제 해법		: 재귀 호출(하노이 탑)
접근 방식		:
결정적 깨달음	: 
오답 원인		: 1. 
				  2.
*/
//////////////////////////////////////////////////////////////////////