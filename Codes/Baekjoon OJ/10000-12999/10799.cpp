#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

const int MAX = 100000;

char ironLaser[MAX + 1];

int main() {
	scanf("%s", ironLaser);

	int len = strlen(ironLaser);

	stack<char> iron;
	int sum = 0;
	
	for (int i = 0; i < len; i++) {
		if (ironLaser[i] == '(') {
			if (i != len - 1 && ironLaser[i + 1] == ')') sum += iron.size(), i++;
			else iron.push('('), sum++;
		}
		else iron.pop();
	}

	printf("%d", sum);

	return 0;
}
/*//////////////////////////////////////////////////////////////////////
문제 해법		: 
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 
				  2. 
*///////////////////////////////////////////////////////////////////////