#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100000;

int arr[MAX + 1];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
		if (arr[i] != arr[i + 1]) cout << arr[i] << ' ';

	return 0;
}
/*/////////////////////////////////////////////////////////////////////
문제 해법		: 
접근 방식		: 
결정적 깨달음		:
오답 원인		: 1.
				  2.
*//////////////////////////////////////////////////////////////////////