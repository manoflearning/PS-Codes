#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
vector<int> ans;

void backtrack(int flag);

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	backtrack(-1);

	return 0;
}

void backtrack(int flag) {
	if (ans.size() == m) {
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << ' ';
		cout << '\n';
	}

	for (int i = flag + 1; i < n; i++) {
		ans.push_back(arr[i]);
		backtrack(i);
		ans.pop_back();
	}
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 백트래킹
접근 방식		: 
결정적 깨달음		:
오답 원인		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////