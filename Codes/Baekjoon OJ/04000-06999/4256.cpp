#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000;

int preorder[MAX], inorder[MAX];

void printPostorder(int preL, int preR, int inL, int inR);

int main() {
	int t;
	cin >> t;

	for (int test = 0; test < t; test++) {
		int c;
		cin >> c;

		for (int i = 0; i < c; i++)
			cin >> preorder[i];
		for (int i = 0; i < c; i++)
			cin >> inorder[i];

		printPostorder(0, c - 1, 0, c - 1);

		cout << '\n';
	}

	return 0;
}

void printPostorder(int preL, int preR, int inL, int inR) {
	//base case
	if (preL > preR) return;

	int root = preorder[preL];

	int flag = find(inorder + inL, inorder + inR, root) - inorder;
	int leftSize = flag - inL;

	printPostorder(preL + 1, preL + leftSize, inL, flag - 1);
	printPostorder(preL + leftSize + 1, preR, flag + 1, inR);
	cout << root << ' ';
}
/*/////////////////////////////////////////////////////////////////////
문제 해법		: 
접근 방식		: 
결정적 깨달음		:
오답 원인		: 1.
				  2.
*//////////////////////////////////////////////////////////////////////