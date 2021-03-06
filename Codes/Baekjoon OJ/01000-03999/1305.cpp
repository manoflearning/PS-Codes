#include <iostream>
#include <vector>
using namespace std;

vector<int> getpi(const string& P);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int L;
	string T;
	cin >> L >> T;

	vector<int> pi = getpi(T);

	/*for (int i = 0; i < L; i++) {
		cout << pi[i] << ' ';
	}*/

	cout << L - pi[L - 1] << '\n';

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