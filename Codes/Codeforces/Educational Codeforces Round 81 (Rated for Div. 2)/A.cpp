#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	for (int test = 0; test < t; test++) {
		int n;
		cin >> n;

		if (n % 2 == 0) {
			for (int i = 0; i < n / 2; i++)
				cout << '1';
			cout << '\n';
		}
		else {
			cout << '7';
			for (int i = 0; i < n / 2 - 1; i++)
				cout << '1';
			cout << '\n';
		}
	}

	return 0;
}