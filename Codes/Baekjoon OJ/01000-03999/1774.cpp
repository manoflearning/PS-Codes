#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXV = 1e3;

struct nnd {
	int n1, n2;
	double d;
};
struct xy {
	int x, y;
};

int N, p[MAXV + 5];
xy arr[MAXV + 5];
vector<nnd> edges;

double dist(int u, int v);
int find(int x);
void merge(int a, int b);
bool cmp(nnd a, nnd b);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(2);

	memset(p, -1, sizeof(p));

	int M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		cin >> arr[i].x >> arr[i].y;
	
	for (int u = 1; u <= N; u++) {
		for (int v = u + 1; v <= N; v++) {
			double d = dist(u, v);
			edges.push_back({ u, v, d });
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b; 
		cin >> a >> b;
		merge(a, b);
	}

	sort(edges.begin(), edges.end(), cmp);

	double sum = 0;
	for (int i = 0; i < edges.size(); i++) {
		if (find(edges[i].n1) == find(edges[i].n2)) continue;
		merge(edges[i].n1, edges[i].n2);
		sum += edges[i].d;
	}

	cout << sum;

	return 0;
}

inline double dist(int u, int v) {
	return sqrt(pow(arr[u].x - arr[v].x, 2) + pow(arr[u].y - arr[v].y, 2));
}

int find(int x) {
	if (p[x] < 0) return x;
	p[x] = find(p[x]);
	return p[x];
}

void merge(int a, int b) {
	int A = find(a), B = find(b);
	if (A == B) return;
	p[B] += p[A];
	p[A] = B;
}

bool cmp(nnd a, nnd b) {
	return a.d < b.d;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: mst
결정적 깨달음		:
시간복잡도		: O(|E|lg|E|)
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////