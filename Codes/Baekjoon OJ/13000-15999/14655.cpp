#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;

	//ù ��° ����
	int round1 = 0;
	for (int i = 0; i < N; i++) {
		int x;  cin >> x;
		round1 += fabs(x);
	}

	//�� ��° ����
	int round2 = 0;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		round2 -= fabs(x);
	}

	//���
	cout << round1 - round2;

	return 0;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: 
������ ������		: 
�ð����⵵		: 
���� ����		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////