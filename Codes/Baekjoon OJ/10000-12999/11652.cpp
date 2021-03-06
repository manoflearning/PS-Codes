#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000000;

long long arr[MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	int max = 0;
	long long flag;

	int count = 1;
	for (int i = 0; i < n; i++) {
		if (count > max) {
			max = count;
			flag = arr[i];
		}

		if (arr[i] == arr[i + 1]) count++;
		else count = 1;
	}

	cout << flag;

	return 0;
}
/*/////////////////////////////////////////////////////////////////////
문제 해법		: 
접근 방식		: 
결정적 깨달음		:
오답 원인		: 1.
				  2.
*//////////////////////////////////////////////////////////////////////