#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll A, B; cin >> A >> B;

	if (A > B) swap(A, B);

	cout << max((ll)0, B - A - 1) << '\n';
	for (ll i = A + 1; i < B; i++)
		cout << i << ' ';

	return 0;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: 
������ ������		:
�ð����⵵		: 
���� ����		: 1. �����÷ο�.. ��¥ ������ �ƴϳ�
				  2.
*/////////////////////////////////////////////////////////////////////