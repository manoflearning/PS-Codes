/*#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };
const long double PI = 3.141592653589793238462643383279502884197;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	//7 7 8
	while (tc--) {
		int l, r, m;
		cin >> l >> r >> m;

		
	}

	return 0;
}*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };
const long double PI = 3.141592653589793238462643383279502884197;

string s;

bool isSub(int i);
bool isSub2(int i);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;

	while (tc--) {
		int n;
		cin >> n >> s;

		int cnt = 0;

		for (int i = 0; i + 6 < s.size(); i++) {
			if (isSub(i)) cnt++;
		}

		if (cnt > 1) {
			cout << "No\n";
			continue;
		}
		if (cnt == 1) {
			cout << "Yes\n";
			for (int i = 0; i < s.size(); i++) {
				if (s[i] != '?') cout << s[i];
				else cout << 'z';
			}
			cout << '\n';
			continue;
		}

		for (int i = 0; i + 6 < s.size(); i++) {
			if (!isSub2(i)) continue;

			string tmp;
			for (int l = i; l < i + 7; l++) {
				tmp.push_back(s[l]);
			}

			s[i] = 'a', s[i + 1] = 'b', s[i + 2] = 'a', s[i + 3] = 'c';
			s[i + 4] = 'a', s[i + 5] = 'b', s[i + 6] = 'a';

			bool Yes = true;

			for (int l = -6; l <= 6; l++) {
				if (i + l < 0 || s.size() <= i + l) continue;
				if (l == 0) continue;
				
				if (isSub(i + l)) Yes = false;
			}

			if (Yes) {
				cnt++;
				break;
			}
			else {
				for (int l = i; l < i + 7; l++) {
					s[l] = tmp[l - i];
				}
			}
		}

		if (cnt == 1) {
			cout << "Yes\n";
			for (int i = 0; i < s.size(); i++) {
				if (s[i] != '?') cout << s[i];
				else cout << 'z';
			}
			cout << '\n';
		}
		else cout << "No\n";
	}

	return 0;
}

bool isSub(int i) {
	if (s[i] != 'a') return false;
	if (s[i + 1] != 'b') return false;
	if (s[i + 2] != 'a') return false;
	if (s[i + 3] != 'c') return false;
	if (s[i + 4] != 'a') return false;
	if (s[i + 5] != 'b') return false;
	if (s[i + 6] != 'a') return false;
	return true;
}

bool isSub2(int i) {
	if (s[i] != 'a' && s[i] != '?') return false;
	if (s[i + 1] != 'b' && s[i + 1] != '?') return false;
	if (s[i + 2] != 'a' && s[i + 2] != '?') return false;
	if (s[i + 3] != 'c' && s[i + 3] != '?') return false;
	if (s[i + 4] != 'a' && s[i + 4] != '?') return false;
	if (s[i + 5] != 'b' && s[i + 5] != '?') return false;
	if (s[i + 6] != 'a' && s[i + 6] != '?') return false;
	return true;
}