#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, M;
	string s;
	cin >> N;
	cin >> M >> s;

	vector<int> lens;

	bool I = (s[0] == 'I');
	int len = I ? 1 : 0;
	for (int i = 1; i < s.size(); i++) {
		if (I) {
			if (s[i] == 'O') {
				len++;
				I = !I;
			}
			else {
				if (len > 1) lens.push_back((len % 2) ? len : len - 1);
				len = 1;
			}
		}
		else {
			if (s[i] == 'I') {
				len++;
				I = !I;
			}
			else {
				if (len > 1) lens.push_back((len % 2) ? len : len - 1);
				len = 0;
			}
		}
	}
	if (len > 1) lens.push_back(len);

	sort(lens.begin(), lens.end());

	int ans = 0;
	for (int len : lens) {
		ans += max((len - (2 * N + 1) + 2) / 2, 0);
	}

	cout << ans << '\n';

	return 0;
}
/*//////////////////////////////////////////////////////////////////
문제 해법		: 
결정적 깨달음		: 
시간복잡도		: O(nlgn)
오답 원인		: 1. 
				  2. 
*///////////////////////////////////////////////////////////////////