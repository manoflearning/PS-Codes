#include <iostream>
using namespace std;

const int MAX = 500000;

int n;
int card[2 * MAX];
int front = 0, rear = 0;

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		card[i - 1] = i;

	rear = n;

	for (int i = 0; front + 1 < rear; i++) {
		if (i % 2 == 0) front++;
		else if (i % 2 == 1) {
			card[rear] = card[front];
			front++;
			rear++;
		}
	}

	printf("%d", card[front]);

	return 0;
}
/*
문제 해법		: 큐
접근 방식		:
결정적 깨달음	:
오답 원인		: 1.
				  2.
*/
//////////////////////////////////////////////////////////////////////