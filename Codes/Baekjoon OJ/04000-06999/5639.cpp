#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10000;

int preorder[MAX + 1];

void printPostorder(int start, int end);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n = 0;

	while (cin >> preorder[n]) n++;

	printPostorder(0, n - 1);

	return 0;
}

void printPostorder(int start, int end) {
	//base case
	if (start > end) return;
	
	int root = preorder[start];

	int flag;
	for (flag = start + 1; flag <= end; flag++)
		if (preorder[flag] > root) break;

	printPostorder(start + 1, flag - 1);
	printPostorder(flag, end);
	cout << root << '\n';
}
/*//////////////////////////////////////////////////////////////////////
문제 해법		: eof 활용, 재귀
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 
				  2. 
*///////////////////////////////////////////////////////////////////////