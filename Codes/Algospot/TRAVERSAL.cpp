#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100;

int preorder[MAX], inorder[MAX];

void print_postorder(int pre_start, int pre_end, int in_start, int in_end);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int test = 0; test < t; test++) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> preorder[i];
		for (int i = 0; i < n; i++)
			cin >> inorder[i];

		print_postorder(0, n - 1, 0, n - 1);
		cout << '\n';
	}

	return 0;
}

void print_postorder(int pre_start, int pre_end, int in_start, int in_end) {
	if (pre_start > pre_end) return;

	int root = preorder[pre_start];

	int flag = find(inorder + in_start, inorder + in_end + 1, root) - inorder;

	int left_size = flag - in_start;
	int right_size = in_end - flag;

	print_postorder(pre_start + 1, pre_start + left_size, in_start, in_start + left_size - 1);
	print_postorder(pre_start + left_size + 1, pre_end, in_start + left_size + 1, in_end);
	
	cout << root << ' ';
}
/*//////////////////////////////////////////////////////////////////////
문제 해법		: 재귀 호출을 활용한 트리 해석
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 
				  2. 
*///////////////////////////////////////////////////////////////////////
