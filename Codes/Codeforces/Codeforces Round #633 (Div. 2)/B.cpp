#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

const int MAX = 1e5;

int arr[MAX + 5];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;

	while (T--) {
		int N; cin >> N;

		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}

		//
		sort(arr + 1, arr + N + 1);

		//
		int mid = (1 + N) / 2;
		cout << arr[mid] << ' ';

		int L = mid - 1, R = mid + 1;
		while (true) {
			if (R <= N) {
				cout << arr[R] << ' ';
				R++;
			}

			if (L < 1 && N < R) break;

			if (1 <= L) {
				cout << arr[L] << ' ';
				L--;
			}

			if (L < 1 && N < R) break;
		}
		cout << endl;
	}

	return 0;
}