#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

struct nnd {
	int n1, n2, d;
};

int N, p[10005];
nnd edges[100005];

int find(int x);
void merge(int a, int b);
bool cmp(nnd a, nnd b) {
	return a.d < b.d;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(p, -1, sizeof(p));

	int M;
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> edges[i].n1 >> edges[i].n2 >> edges[i].d;
	}

	sort(edges, edges + M, cmp);

	ll sum = 0;
	for (int i = 0; i < M; i++) {
		if (find(edges[i].n1) != find(edges[i].n2)) {
			merge(edges[i].n1, edges[i].n2);
			sum += edges[i].d;
		}
	}

	cout << sum;

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
문제 해법		: 크루스칼의 최소 스패닝 트리
결정적 깨달음		:
시간복잡도		:
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////