#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

const int MAX = 1e5;

struct nd {
	int n, d;
};
struct nnd {
	int n1, n2, d;
};

int N, p[MAX + 5];
nd x[MAX + 5], y[MAX + 5], z[MAX + 5];
vector<nnd> E;

bool cmp(nd a, nd b) {
	return a.d < b.d;
}
bool ncmp (nnd a, nnd b) {
	return a.d < b.d;
}

int find(int x);
void merge(int a, int b);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	memset(p, -1, sizeof(p));

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x[i].d >> y[i].d >> z[i].d;
		x[i].n = y[i].n = z[i].n = i;
	}

	sort(x, x + N, cmp);
	sort(y, y + N, cmp);
	sort(z, z + N, cmp);

	for (int i = 0; i < N - 1; i++) {
		E.push_back({ x[i].n, x[i + 1].n, x[i + 1].d - x[i].d });
		E.push_back({ y[i].n, y[i + 1].n, y[i + 1].d - y[i].d });
		E.push_back({ z[i].n, z[i + 1].n, z[i + 1].d - z[i].d });
	}

	sort(E.begin(), E.end(), ncmp);

	ll cost = 0;
	for (int i = 0; i < E.size(); i++) {
		if (find(E[i].n1) == find(E[i].n2)) continue;
		cost += E[i].d;
		merge(E[i].n1, E[i].n2);
	}

	cout << cost;

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
결정적 깨달음		: x, y, z를 각각 따로 정렬. 
시간복잡도		: O(|V|lg|V|)
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////