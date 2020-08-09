#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char word[100][14];
	
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%s", word[i]);

	for (int i = 0; i < n; i++) {
		for (int l = 0; l <= i; l++) {
			if (strlen(word[i]) == strlen(word[l])) {
				int len = strlen(word[i]);
				bool check = true;

				for (int j = 0; j < len / 2 + 1; j++)
					if (word[i][j] != word[l][len - j - 1]) check = false;

				if (check) {
					printf("%d %c", len, word[i][len / 2]);

					i = n, l = n;
					break;
				}
			}
		}
	}
	
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