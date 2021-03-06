#include <iostream>
#include <list>
#include <cstring>
using namespace std;

list<char> password;

list<char>::iterator it = password.end();

int main() {
	int t;
	scanf("%d", &t);

	for (int test = 0; test < t; test++) {
		char memo[1000001];
		scanf("%s", memo);

		int len = strlen(memo);

		for (int i = 0; i < len; i++) {
			if (memo[i] == '-') {
				if (it != password.begin()) it = password.erase(--it);
			}
			else if (memo[i] == '<') {
				if (it != password.begin()) it--;
			}
			else if (memo[i] == '>') {
				if (it != password.end()) it++;
			}
			else password.insert(it, memo[i]);
		}

		list<char>::iterator print = password.begin();
		for (; print != password.end(); print++)
			printf("%c", *print);
		printf("\n");

		password.clear();
		it = password.end();
	}

	return 0;
}
/*
문제 해법		: 연결 리스트 및 구현
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 
				  2. 
*/
//////////////////////////////////////////////////////////////////////