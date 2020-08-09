#include <iostream>
#define ll long long
using namespace std;

ll GCD(ll a, ll b);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll A, B;
	cin >> A >> B;

	ll gcd = GCD(A, B);

	string s(gcd, '1');
	cout << s << endl;

	return 0;
}

ll GCD(ll a, ll b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: ����
������ ������		: ������ �Է����� �־����� �� ���� �ִ�������ŭ�� �ڸ����� ���� 1�� �̷���� ���̴�.
�ð����⵵		:
���� ����		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////