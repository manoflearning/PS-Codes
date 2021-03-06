#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> inorder, postorder;

void printPreorder(int in_s, int in_e, int post_s, int post_e);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	inorder.resize(n);
	postorder.resize(n);

	for (int i = 0; i < n; i++)
		cin >> inorder[i];
	for (int i = 0; i < n; i++)
		cin >> postorder[i];

	printPreorder(0, n - 1, 0, n - 1);

	return 0;
}

void printPreorder(int in_s, int in_e, int post_s, int post_e) {
	//base case
	if (in_s > in_e) return;

	int root = postorder[post_e];

	int flag = find(inorder.begin() + in_s, inorder.begin() + in_e + 1, root) - inorder.begin();
	int size = flag - in_s;

	cout << root << ' ';
	printPreorder(in_s, in_s + size - 1, post_s, post_s + size - 1);
	printPreorder(in_s + size + 1, in_e, post_s + size, post_e - 1);
}
/*//////////////////////////////////////////////////////////////////////
문제 해법		: 재귀 호출
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 잘못된 base case 설정
				  2. 
*///////////////////////////////////////////////////////////////////////