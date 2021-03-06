#include <iostream>
#include <climits>
using namespace std;

int arr[300001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//
	int t;
	cin >> t;

	for (int test = 0; test < t; test++) {
		int n;
		cin >> n;

		bool increase = true, decrease = true;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];

			if (increase) {
				if (i - 1 <= arr[i]) continue;
				else {
					increase = false;
					if (n - i > arr[i]) decrease = false;
					if (n - (i - 1) > arr[i - 1]) decrease = false;
				}
			}
			else {
				if (n - i <= arr[i]) continue;
				else decrease = false;
			}
		}

		if (increase || decrease) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}