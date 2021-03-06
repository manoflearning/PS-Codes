#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100;

struct xy {
	double x, y;
};
struct nnd {
	int n1, n2;
	double d;
};

int N, p[MAX + 5];
xy V[MAX + 5];
vector<nnd> E;

bool cmp(nnd a, nnd b);
double dist(xy a, xy b);
int find(int x);
void merge(int a, int b);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(3);

	memset(p, -1, sizeof(p));

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> V[i].x >> V[i].y;

	for (int u = 0; u < N; u++) {
		for (int v = u + 1; v < N; v++) {
			E.push_back({ u, v, dist(V[u], V[v]) });
		}
	}

	sort(E.begin(), E.end(), cmp);

	double cost = 0;
	for (int i = 0; i < E.size(); i++) {
		if (find(E[i].n1) == find(E[i].n2)) continue;
		cost += E[i].d;
		merge(E[i].n1, E[i].n2);
	}

	cout << cost;

	return 0;
}

bool cmp(nnd a, nnd b) {
	return a.d < b.d;
}
double dist(xy a, xy b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
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
시간복잡도		: O(n^2lgn) (|E| == nC2)
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////