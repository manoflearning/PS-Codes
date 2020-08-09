#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int S1, S2;
	cin >> S1 >> S2;

	bool S1_ac = true, S2_ac = true;

	for (int i = 0; i < S1; i++) {
		int a, b; cin >> a >> b;
		if (a != b) S1_ac = false;
	}

	for (int i = 0; i < S2; i++) {
		int a, b; cin >> a >> b;
		if (a != b) S2_ac = false;
	}

	if (S1_ac && S2_ac) cout << "Accepted";
	else if (S1_ac && !S2_ac) cout << "Why Wrong!!!";
	else cout << "Wrong Answer";

	return 0;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 구현
결정적 깨달음		: 
시간복잡도		: 
오답 원인		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////