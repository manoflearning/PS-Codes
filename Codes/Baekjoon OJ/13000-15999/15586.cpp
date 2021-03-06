#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

const int MAX = 100000;

struct nnv {
	int n1; int n2; int v;
};
struct seqkn {
	int seq; int k; int n;
};

int N, Q, ans[MAX + 5], p[MAX + 5];
nnv graph[MAX + 5];
seqkn qeory[MAX + 5];

bool cmpNnv(nnv a, nnv b) {
	return a.v > b.v;
}
bool cmpSeqkn(seqkn a, seqkn b) {
	return a.k > b.k;
}

int find(int n);
void merge(int a, int b);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	memset(p, -1, sizeof(p));

	cin >> N >> Q;

	for (int i = 0; i < N - 1; i++) {
		cin >> graph[i].n1 >> graph[i].n2 >> graph[i].v;
	}
	//간선 정보를 USADO를 기준으로 내림차순 정렬
	sort(graph, graph + N, cmpNnv);

	for (int i = 0; i < Q; i++) {
		qeory[i].seq = i;
		cin >> qeory[i].k >> qeory[i].n;
	}
	//쿼리 정보를 k를 기준으로 내림차순 정렬
	sort(qeory, qeory + Q, cmpSeqkn);

	int flag = 0;
	for (int i = 0; i < Q; i++) {
		while (flag < N && graph[flag].v >= qeory[i].k) {
			merge(graph[flag].n1, graph[flag].n2);
			flag++;
		}
		ans[qeory[i].seq] = -p[find(qeory[i].n)] - 1;
	}

	for (int i = 0; i < Q; i++)
		cout << ans[i] << '\n';

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
	p[B] += p[A];
	p[A] = B;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 오프라인 쿼리, 유니온 파인드
접근 방식		: 
결정적 깨달음		: 쿼리를 k를 기준으로 내림차순하여, 순서대로 답을 구하면 중복 연산을 막을 수 있다.
시간복잡도		: O(NlogN)
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////