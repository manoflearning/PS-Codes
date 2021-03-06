#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 100;

char arr[MAX + 1];
vector<char> stack;

int main() {
	while (true) {
		scanf("%[^\n]s", arr);
		getchar();
		if (arr[0] == '.' && strlen(arr) == 1) break;
		
		bool check = true;
		
		for (int i = 0; i < strlen(arr); i++) {
			if (arr[i] == '(' || arr[i] == '[')
				stack.push_back(arr[i]);
			else if (!stack.empty() && stack.back() == '(' && arr[i] == ')')
				stack.pop_back();
			else if (!stack.empty() && stack.back() == '[' && arr[i] == ']')
				stack.pop_back();
			else if (arr[i] == ')' || arr[i] == ']') {
				check = false;
				break;
			}
		}
		
		if (check && stack.empty()) printf("yes\n");
		else printf("no\n");

		stack.resize(0);
	}

	return 0;
}
/*
문제 해법		: stack
접근 방식		: 
결정적 깨달음	: 
오답 원인		: 1. scanf("%s", arr); -> scanf("%[^\n]s", arr);
				  2. 버퍼 클리어
*/
//////////////////////////////////////////////////////////////////////