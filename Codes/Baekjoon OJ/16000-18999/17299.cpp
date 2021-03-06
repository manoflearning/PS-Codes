#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

const int MAX = 1000000;

int arr[MAX], times[MAX + 1];
int ans[MAX];

int main() {
	memset(ans, -1, sizeof(ans));

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		times[arr[i]]++;
	}

	stack<int> arrs;
	for (int i = 0; i < n; i++) {
		while (!arrs.empty() && times[arr[arrs.top()]] < times[arr[i]]) {
			ans[arrs.top()] = arr[i];
			arrs.pop();
		}

		arrs.push(i);
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';

	return 0;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 스택
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////