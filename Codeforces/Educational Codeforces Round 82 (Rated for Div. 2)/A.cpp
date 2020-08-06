#include <iostream>
#include <cstring>
using namespace std;

char arr[101];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//
	int t;
	cin >> t;

	for (int test = 0; test < t; test++) {
		cin >> arr;

		int ans = 0, cnt = 0;

		int len = strlen(arr);
		bool ex1 = false;
		for (int i = 0; i < len; i++) {
			if (ex1) {
				if (arr[i] == '1') {
					ans += cnt;
					cnt = 0;
				}
				else cnt++;
			}
			else if (arr[i] == '1') ex1 = true;
		}

		cout << ans << '\n';
	}

	return 0;
}