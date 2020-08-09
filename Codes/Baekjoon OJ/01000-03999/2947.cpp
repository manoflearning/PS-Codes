#include <iostream>
#include <algorithm>
using namespace std;

int pieces[5];

int main() {
	for (int i = 0; i < 5; i++)
		cin >> pieces[i];

	for (int i = 0; i < 5; i++) {
		for (int l = 1; l < 5 - i; l++) {
			if (pieces[l - 1] > pieces[l]) {
				swap(pieces[l - 1], pieces[l]);

				for (int flag = 0; flag < 5; flag++)
					cout << pieces[flag] << ' ';
				cout << '\n';
			}
		}
	}

	return 0;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 버블 소트
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////