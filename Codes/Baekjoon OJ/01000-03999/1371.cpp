#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int cnt[26] = { 0, };

	string s;
	while (cin >> s) {
		for (char x : s) cnt[x - 'a']++;
	}

	int aMax = -1;
	for (int i = 0; i < 26; i++) {
		aMax = max(aMax, cnt[i]);
	}

	vector<char> ans;
	for (int i = 0; i < 26; i++) {
		if (aMax == cnt[i]) ans.push_back(i + 'a');
	}

	for (char x : ans) cout << x;

	return 0;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 
결정적 깨달음		: 
시간복잡도		: O(|s|)
오답 원인		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////