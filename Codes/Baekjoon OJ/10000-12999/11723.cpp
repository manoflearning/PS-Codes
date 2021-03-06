#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<bool> exist(21, false);

	int M; cin >> M;

	while (M--) {
		string s; cin >> s;
		if (s == "add") {
			int x; cin >> x;
			exist[x] = true;
		}
		else if (s == "remove") {
			int x; cin >> x;
			exist[x] = false;
		}
		else if (s == "check") {
			int x; cin >> x;
			if (exist[x]) cout << "1\n";
			else cout << "0\n";
		}
		else if (s == "toggle") {
			int x; cin >> x;
			exist[x] = !exist[x];
		}
		else if (s == "all") {
			fill(exist.begin() + 1, exist.end(), true);
		}
		else if (s == "empty") {
			fill(exist.begin() + 1, exist.end(), false);
		}
	}

	return 0;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 
결정적 깨달음		: 
시간복잡도		: 
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////