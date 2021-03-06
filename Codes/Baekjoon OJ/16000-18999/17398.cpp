#include <iostream>
#include <vector>
#define ll long long
using namespace std;

const int MAX = 100000;

int n, m, q;
vector<int> set(MAX + 1, -1);
int cnnct[MAX + 1][2];
bool cannot[MAX + 1];
int Q[MAX + 1];

int find(int x);
void merge(int a, int b);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//
	cin >> n >> m >> q;

	for (int i = 1; i <= m; i++) {
		cin >> cnnct[i][0] >> cnnct[i][1];
	}

	for (int i = 1; i <= q; i++) {
		cin >> Q[i];
		cannot[Q[i]] = true;
	}

	for (int i = 1; i <= m; i++) {
		if (cannot[i]) continue;
		merge(cnnct[i][0], cnnct[i][1]);
	}
	//
	ll ans = 0;
	for (int i = q; i >= 1; i--) {
		int a = cnnct[Q[i]][0], b = cnnct[Q[i]][1];
		if (find(a) != find(b)) ans += (ll)set[find(a)] * set[find(b)];
		merge(a, b);
	}

	cout << ans;

	return 0;
}

int find(int x) {
	if (set[x] < 0) return x;
	set[x] = find(set[x]);
	return set[x];
}
void merge(int a, int b) {
	int A = find(a), B = find(b);
	if (A != B) {
		set[A] += set[B];
		set[B] = A;
	}
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 유니온 파인드
접근 방식		: 
결정적 깨달음		: 한 집합을 두 집합으로 나누는 연산을 역으로 하면, 두 집합을 합치는 연산이다.
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////