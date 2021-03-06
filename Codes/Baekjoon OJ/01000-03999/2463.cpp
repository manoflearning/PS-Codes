#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

const int MAX = 100000;

struct nnv {
	int n1; int n2; int v;
};

int N, M, p[MAX + 5];
nnv arr[MAX + 5];
ll ans, cost;

bool cmp(nnv a, nnv b) {
	return a.v > b.v;
}

int find(int n);
void merge(int a, int b);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(p, -1, sizeof(p));

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> arr[i].n1 >> arr[i].n2 >> arr[i].v;
		cost += arr[i].v;
	}
	//간선 정보를 v를 기준으로 내림차순
	sort(arr, arr + M, cmp);

	for (int i = 0; i < M; i++) {
		merge(arr[i].n1, arr[i].n2);
		cost -= arr[i].v;
	}

	cout << ans % (ll)1e9;

	return 0;
}

int find(int n) {
	if (p[n] < 0) return n;
	p[n] = find(p[n]);
	return p[n];
}
void merge(int a, int b) {
	int A = find(a), B = find(b);
	if (A == B) return;
	//A가 포함된 집합의 모든 노드와 B가 포함된 집합의 모든 노드가 서로 연결되는 상황.
	ans += cost * -p[A] * -p[B];
	p[B] += p[A];
	p[A] = B;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 유니온 파인드
결정적 깨달음		: 간선 정보를 v를 기준으로 내림차순.
시간복잡도		: O(nlogn)
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////