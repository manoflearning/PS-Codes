#include <iostream>
#include <vector>
using namespace std;

int N;
char shift[1000];

vector<int> kmp(string& T, const string& P);
vector<int> getpi(const string& P);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;

	while (tc--) {
		string s, P, T;
		cin >> s >> P >> T;

		N = s.size();
		for (int i = 0; i < N; i++) {
			shift[s[(i + 1) % N]] = s[i];
		}

		vector<int> ans = kmp(T, P);

		if (ans.size() == 0) cout << "no solution\n";
		else if (ans.size() == 1) {
			cout << "unique: " << ans[0] << '\n';
		}
		else {
			cout << "ambiguous: ";
			for (int x : ans) cout << x << ' ';
			cout << '\n';
		}
	}

	return 0;
}

vector<int> kmp(string& T, const string& P) {
	vector<int> ret;

	vector<int> pi = getpi(P);
	for (int s = 0; s < N; s++) {
		int begin = 0, matched = 0, cnt = 0;
		while (begin + matched < T.size()) {
			if (T[begin + matched] == P[matched]) {
				matched++;
				if (matched == P.size()) cnt++;
			}
			else {
				if (matched == 0) begin++;
				else {
					begin += matched - pi[matched - 1];
					matched = pi[matched - 1];
				}
			}
		}

		if (cnt == 1) ret.push_back(s);
		//cout << s << ' ' << T << '\n';
		for (int i = 0; i < T.size(); i++) {
			T[i] = shift[T[i]];
		}
	}

	return ret;
}

vector<int> getpi(const string& P) {
	vector<int> pi(P.size());

	int begin = 1, matched = 0;
	while (begin + matched < P.size()) {
		if (P[begin + matched] == P[matched]) {
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}

	return pi;
}