#include <iostream>
#include <algorithm>
using namespace std;

int arr[(int)1e5];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, s; 
	cin >> n >> s;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int L = 0, sum = 0, min_len = 1e5 + 1;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		while (sum >= s && L <= i) {
			min_len = min(min_len, i - L + 1);
			sum -= arr[L];
			L++;
		}
	}

	if (min_len == 1e5 + 1) cout << 0;
	else cout << min_len;

	return 0;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: ��������
������ ������		: 
�ð����⵵		: O(n)
���� ����		: 1. "���� s��"�� �ƴ϶� "���� s �̻���"�̾���. ������ �߸� ����. 
				  2. ���̰� 1�� ��츦 üũ���� ����.
				  3. sum == s�� ��츦 üũ���� ����.
*/////////////////////////////////////////////////////////////////////