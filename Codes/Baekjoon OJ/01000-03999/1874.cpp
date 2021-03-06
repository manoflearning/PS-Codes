#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> print;
vector<int> stack;
vector<char> ans;

int main() {
	scanf("%d", &n);

	print.resize(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &print[i]);

	for (int i = 1; i <= n; i++) {
		stack.push_back(i);
		ans.push_back('+');

		while (!stack.empty() && stack.back() == print.front()) {
			stack.pop_back();
			ans.push_back('-');

			print.erase(print.begin());
		}
	}

	if (stack.empty() && print.empty()) {
		int flag = ans.size();
		for (int i = 0; i < flag; i++)
			printf("%c\n", ans[i]);
	}
	else printf("NO");

	return 0;
}
/*
문제 해법		: 스택
접근 방식		: 
결정적 깨달음	: 
오답 원인		: 1. 
				  2. 
*/
//////////////////////////////////////////////////////////////////////