#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int n;
string s, sp;
map<string, int> mp;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;

	while (T--) {
		mp.clear();

		cin >> n >> s;
		
		/*for (int k = 1; k <= n; k++) {
			sp = s;
			for (int i = 1; i <= n - k + 1; i++) {
				reverse(sp.begin() + i - 1, sp.begin() + (i + k - 1));
			}
			cout << sp << '\n';
			mp.insert({ sp, k });
		}*/

		for (int k = 1; k <= n; k++) {
			sp.clear();
			
			for (int i = k - 1; i <= n - 1; i++)
				sp.push_back(s[i]);

			if ((k % 2 == 0 && n % 2 == 0) || (k % 2 == 1 && n % 2 == 1)) {
				for (int i = k - 2; i >= 0; i--)
					sp.push_back(s[i]);
			}
			else {
				for (int i = 0; i <= k - 2; i++)
					sp.push_back(s[i]);
			}
			mp.insert({ sp, k });
		}

		cout << mp.begin()->first << '\n' << mp.begin()->second << '\n';
	}

	return 0;
}