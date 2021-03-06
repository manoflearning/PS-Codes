#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1e5;

vector<int> getpi(const string& P);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string T;
	cin >> T;
	//getline(cin, T);

	int N; cin >> N;
	//getchar();

	vector<string> PArr(N);
	vector<vector<int>> piArr(N);
	
	for (int i = 0; i < N; i++) {
		cin >> PArr[i];
		//getline(cin, PArr[i]);
		piArr[i] = getpi(PArr[i]);
	}

	vector<int> dp(MAX + 5);
	vector<int> beginArr(N), matchedArr(N);

	for (int pos = 0; pos < T.size(); pos++) {
		if (0 < pos) dp[pos] = dp[pos - 1];

		for (int i = 0; i < N; i++) {
			string& P = PArr[i];
			vector<int>& pi = piArr[i];
			int& begin = beginArr[i], & matched = matchedArr[i];
			
			while (begin + matched <= pos && begin <= T.size() - P.size()) {
				if (matched < P.size() && T[begin + matched] == P[matched]) {
					matched++;

					if (matched == P.size() && begin + matched - 1 == pos) {
						int val = P.size();
						if (0 <= pos - (int)P.size())
							val += dp[pos - (int)P.size()];

						dp[pos] = max(dp[pos], val);
					}
				}
				else {
					if (matched == 0) begin++;
					else {
						begin += matched - pi[matched - 1];
						matched = pi[matched - 1];
					}
				}
			}
		}
	}

	cout << dp[T.size() - 1] << '\n';

	return 0;
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