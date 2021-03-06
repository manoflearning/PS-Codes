#include <iostream>
#include <cstring>
using namespace std;

char quadtree[1001];

void reverse(int left, int right);
int length(int local);

int main() {
	int t;
	scanf("%d", &t);

	for (int test = 0; test < t; test++) {
		scanf("%s", quadtree);
		
		reverse(0, strlen(quadtree));
		
		printf("%s\n", quadtree);
	}

	return 0;
}

void reverse(int left, int right) {
	//base case
	if (quadtree[left] != 'x') return;

	int f[4];
	f[0] = left + 1;
	for (int i = 1; i < 4; i++) {
		if (quadtree[f[i - 1]] == 'x') f[i] = length(f[i - 1] + 1) + 1;
		else f[i] = f[i - 1] + 1;
	}
	
	reverse(f[0], f[1]);
	reverse(f[1], f[2]);
	reverse(f[2], f[3]);
	reverse(f[3], right);

	char tmp1[1001], tmp2[1001];
	for (int i = f[0]; i < f[2]; i++)
		tmp1[i] = quadtree[i];
	for (int i = f[2]; i < right; i++)
		tmp2[i] = quadtree[i];
	for (int i = f[0]; i < f[2]; i++)
		quadtree[i + right - f[2]] = tmp1[i];
	for (int i = f[2]; i < right; i++)
		quadtree[i - f[2] + f[0]] = tmp2[i];
}
int length(int local) {
	int ans, count = 0;
	for (int i = local; ; i++) {
		if (quadtree[i] == 'x') i = length(i + 1);

		count++;

		if (count == 4) {
			ans = i;
			break;
		}
	}

	return ans;
}
/*
문제 해법		: 분할 정복
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. static int 형의 잘못된 사용.
				  2. 
*/
//////////////////////////////////////////////////////////////////////
