#include <iostream>
#define ll long long
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string A, B;
	cin >> A >> B;

	ll ans = 0;
	for (char a : A) {
		for (char b : B) {
			ans += (a - '0') * (b - '0');
		}
	}

	cout << ans;

	return 0;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: 
������ ������		: 
�ð����⵵		: O(|A| * |B|)
���� ����		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////