#include <iostream>
#include <algorithm>
using namespace std;

int arr[200000];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, a, b, k;
	cin >> n >> a >> b >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		arr[i] = arr[i] % (a + b);
		if (arr[i] == 0) arr[i] += (a + b);
	}
	//
	sort(arr, arr + n);
	//
	int count = 0;
	for (int i = 0; i < n; i++) {
		arr[i] -= a;

		while (k > 0 && arr[i] > 0) {
			k--;
			arr[i] -= a;
		}
		
		if (arr[i] <= 0) count++;
	}

	cout << count;

	return 0;
}