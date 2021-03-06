#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 2 * 1e5;

struct nnd {
	int n1, n2, d;
};

int N, M, p[MAX + 5];
nnd E[MAX + 5];

bool cmp(nnd a, nnd b) {
	return a.d < b.d;
}

int find(int x);
void merge(int a, int b);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		memset(p, -1, sizeof(p));

		cin >> N >> M;

		if (N == 0 && M == 0) break;

		int cost = 0;

		for (int i = 0; i < M; i++) {
			cin >> E[i].n1 >> E[i].n2 >> E[i].d;
			cost += E[i].d;
		}

		sort(E, E + M, cmp);

		for (int i = 0; i < M; i++) {
			if (find(E[i].n1) == find(E[i].n2)) continue;
			cost -= E[i].d;
			merge(E[i].n1, E[i].n2);
		}

		cout << cost << '\n';
	}

	return 0;
}

int find(int x) {
	if (p[x] < 0) return x;
	p[x] = find(p[x]);
	return p[x];
}
void merge(int a, int b) {
	int A = find(a), B = find(b);
	if (A == B) return;
	p[A] += p[B];
	p[B] = A;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 크루스칼 알고리즘
결정적 깨달음		: 
시간복잡도		: O(|E|lg|E|)
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////