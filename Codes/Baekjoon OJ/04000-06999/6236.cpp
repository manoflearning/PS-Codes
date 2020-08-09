#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

const int MAX = 1e5;

int N, M, cost[MAX + 5];

int lower_bound(int L, int R);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;

	int L = 0, R = 0;
	for (int i = 0; i < N; i++) {
		cin >> cost[i];
		L = max(L, cost[i]);
		R += cost[i];
	}
	
	cout << lower_bound(L, 1e9);
	
	return 0;
}

int lower_bound(int L, int R) {
	//base case
	if (L == R) return L;

	int mid = (L + R) / 2;
	
	int money = mid, cnt = 1;
	for (int i = 0; i < N; i++) {
		if (money >= cost[i]) money -= cost[i];
		else {
			money = mid - cost[i];
			cnt++;
		}
	}

	if (cnt <= M) return lower_bound(L, mid);
	else return lower_bound(mid + 1, R);
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: �̺� Ž��(lower bound)
������ ������		: lower bound�� Ž�� ���Ҹ� �������� ������ ���� �Ҹ���, �ڽ��� ������ �������� ��� ���� �������� �Ѵ�.
�ð����⵵		: O(nlg(10^11))
���� ����		: 1. 1e11�� int�� ���� ���̴�..
				  2. 
*/////////////////////////////////////////////////////////////////////