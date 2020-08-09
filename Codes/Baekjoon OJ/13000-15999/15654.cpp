#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
vector<int> ans;
bool exist[8];

void backtrack();

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	backtrack();

	return 0;
}

void backtrack() {
	if (ans.size() == m) {
		for (int i = 0; i < m; i++)
			cout << ans[i] << ' ';
		cout << '\n';
	}

	for (int i = 0; i < n; i++) {
		if (exist[i]) continue;

		exist[i] = true;
		ans.push_back(arr[i]);

		backtrack();

		exist[i] = false;
		ans.pop_back();
	}
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: ��Ʈ��ŷ
���� ���		: ���� �������� ����(���������� ����ؾ� �ϱ� ����) -> �ߺ� ������ bool �迭��, ��� �ѹ� ȣ�� �� �� ���� ���� -> ������ ũ�Ⱑ m�̸� ���
������ ������		:
���� ����		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////