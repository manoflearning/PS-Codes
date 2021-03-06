#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

long long int alpha[10];
vector<bool> check0(10, true);

long long int pow10[12] = { 1, };

void counter(char arr[]);
void determine0();

int main() {
	for (int i = 1; i < 12; i++)
		pow10[i] = pow10[i - 1] * 10;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char arr[13];
		scanf("%s", arr);

		check0[arr[0] - 'A'] = false;

		counter(arr);
	}

	determine0();

	sort(alpha + 1, alpha + 10);

	long long int ans = 0;
	for (int i = 0; i < 10; i++)
		ans += i * alpha[i];
	printf("%lld", ans);

	return 0;
}

void counter(char arr[]) {
	int len = strlen(arr);
	for (int flag = 0; flag < len; flag++)
		alpha[arr[flag] - 'A'] += pow10[len - flag - 1];
}

void determine0() {
	int flag;
	long long int min = 50 * pow10[11] + 1;
	for (int i = 0; i < 10; i++)
		if (check0[i] && alpha[i] < min) {
			flag = i;
			min = alpha[i];
		}

	alpha[flag] = alpha[0];
	alpha[0] = min;
}
/*
문제 해법		:
접근 방식		:
결정적 깨달음		:
오답 원인		: 1. 최소값을 저장하는 변수의 초기화가 잘못됨. INT_MAX로 초기화했으나, 입력에 따라 INT_MAX보다 큰 최소값이 있을 수 있음.
				  2.
*/
//////////////////////////////////////////////////////////////////////