#include <iostream>
#include <vector>
using namespace std;

int n;
int last_name[26];

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char name[31];
		scanf("%s", name);

		last_name[name[0] - 97]++;
	}

	bool check = false;

	for (int i = 0; i < 26; i++) {
		if (last_name[i] >= 5) {
			printf("%c", i + 97);
			check = true;
		}
	}

	if (!check) printf("PREDAJA");
}
/*
문제 해법		: 카운팅 정렬
접근 방식		: 
결정적 깨달음	: 
오답 원인		: 1. 
				  2.
*/
////////////////////////////////////////////////////////////////////////////////
