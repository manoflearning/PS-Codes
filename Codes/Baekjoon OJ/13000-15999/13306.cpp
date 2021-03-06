#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 200000;
const int YES = 1, NO = 2;

int n, q;
int par[MAX + 1], set[MAX + 1];
int qry[2 * MAX][3];
int ans[2 * MAX];

int find(int x);
void merge(int a, int b);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(set, -1, sizeof(set));

	cin >> n >> q;

	for (int i = 2; i <= n; i++) {
		cin >> par[i];
		set[i] = par[i];
	}

	for (int i = 0; i < q + n - 1; i++) {
		cin >> qry[i][0];

		if (qry[i][0] == 0) {
			cin >> qry[i][1];
			set[qry[i][1]] = -1;
		}
		else {
			cin >> qry[i][1] >> qry[i][2];
		}
	}
	//
	for (int i = q + n - 2; i >= 0; i--) {
		if (qry[i][0] == 0) merge(qry[i][1], par[qry[i][1]]);
		else {
			if (find(qry[i][1]) == find(qry[i][2])) ans[i] = YES;
			else ans[i] = NO;
		}
	}
	//
	for (int i = 0; i < q + n - 1; i++) {
		if (ans[i] == YES) cout << "YES\n";
		else if (ans[i] == NO) cout << "NO\n";
	}

	return 0;
}

int find(int x) {
	if (set[x] < 0) return x;
	set[x] = find(set[x]);
	return set[x];
}
void merge(int a, int b) {
	int A = find(a), B = find(b);
	if (A != B) set[A] = B;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 유니온 파인드
접근 방식		: 
결정적 깨달음		: 질의를 역순으로 풀음
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////