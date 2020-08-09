#include <iostream>
#include <map>
using namespace std;

map<string, int> mp;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		string s, x;
		cin >> s >> x;

		if (x == "enter") mp.insert({ s, 0 });
		else mp.erase(s);
	}

	map<string, int>::iterator it = mp.end();

	while (it != mp.begin()) {
		--it;
		cout << it->first << '\n';
	}

	return 0;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: ���� Ž�� Ʈ��
������ ������		: 
�ð����⵵		: 
���� ����		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////