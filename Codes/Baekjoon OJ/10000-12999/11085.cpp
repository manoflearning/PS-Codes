#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct bb {
	int a;
	int b;
	int v;
};

int p, w, s, e;
vector<bb> road;
int pp[1000];

bool cmp(bb a, bb b);
int find(int x);
void merge(int a, int b);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(pp, -1, sizeof(pp));
	//
	cin >> p >> w;
	cin >> s >> e;

	for (int i = 0; i < w; i++) {
		int a, b, v;
		cin >> a >> b >> v;
		road.push_back({ a,b,v });
	}
	//
	sort(road.begin(), road.end(), cmp);

	for (int i = 0; i < road.size(); i++) {
		merge(road[i].a, road[i].b);

		if (find(s) == find(e)) {
			cout << road[i].v;
			break;
		}
	}

	return 0;
}

bool cmp(bb a, bb b) {
	return a.v > b.v;
}
int find(int x) {
	if (pp[x] < 0) return x;
	pp[x] = find(pp[x]);
	return pp[x];
}
void merge(int a, int b) {
	int A = find(a), B = find(b);
	if (A == B) return;
	pp[A] = B;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 유니온 파인드
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////