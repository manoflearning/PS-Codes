#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char word[101];
	scanf("%s", word);

	int len = strlen(word);
	for (int i = 0; i < len; i++) {
		if ('a' <= word[i] && word[i] <= 'z')
			printf("%c", word[i] - 'a' + 'A');
		else printf("%c", word[i] - 'A' + 'a');
	}

	return 0;
}
/*
���� �ع�		: 
���� ���		: 
������ ������		: 
���� ����		: 1. 
				  2. 
*/
//////////////////////////////////////////////////////////////////////