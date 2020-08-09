#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int g; cin >> g;

	ll L = 1;
	bool ans = false;
	for (ll i = 2; i <= g; i++) {
		while (i * i - L * L > g) L++;
		if (i * i - L * L == g) {
			cout << i << '\n';
			ans = true;
		}
	}

	if (!ans) cout << -1;

	return 0;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: �� ������ ����
������ ������		: 
�ð����⵵		: O(n)
���� ����		: 1. ������ �����԰� ���� ��츦 �������� ����
				  2. 
*/////////////////////////////////////////////////////////////////////