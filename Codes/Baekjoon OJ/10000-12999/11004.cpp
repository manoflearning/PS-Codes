#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 5000000;

int arr[MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	nth_element(arr, arr + k - 1, arr + n);
	cout << arr[k - 1];

	return 0;
}
/*/////////////////////////////////////////////////////////////////////
문제 해법		: 
접근 방식		: 
결정적 깨달음		:
오답 원인		: 1.
				  2.
*//////////////////////////////////////////////////////////////////////