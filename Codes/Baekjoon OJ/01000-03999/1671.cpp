#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 50;
const int MAXV = 2 * MAX;

struct sfi {
	int s, f, i;
};

int N, A[MAXV + 5], B[MAX + 5];
sfi arr[MAX + 5];
vector<int> adj[MAXV + 5];
bool visited[MAXV + 5];

void input();
bool cmp(sfi a, sfi b);
void graph_modeling();
bool canEat(sfi a, sfi b);
int bMatch();
bool dfs(int a);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();

	sort(arr + 1, arr + 1 + N, cmp);

	graph_modeling();

	int ans = bMatch();
	cout << ans << '\n';

	return 0;
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i].s >> arr[i].f >> arr[i].i;
	}
}

bool cmp(sfi a, sfi b) {
	if (a.s != b.s) return a.s > b.s;
	if (a.f != b.f) return a.f > b.f;
	return a.i > b.i;
}

void graph_modeling() {
	for (int i = 1; i <= N; i++) {
		for (int l = i + 1; l <= N; l++) {
			if (canEat(arr[i], arr[l])) {
				adj[2 * i - 1].push_back(l);
				adj[2 * i].push_back(l);
			}
		}
	}
}

bool canEat(sfi a, sfi b) {
	return (a.s >= b.s) && (a.f >= b.f) && (a.i >= b.i);
}

int bMatch() {
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));

	int ret = 0;
	for (int i = 1; i <= 2 * N; i++) {
		memset(visited, 0, sizeof(visited));
		if (dfs(i)) ret++;
	}
	return N - ret;
}

bool dfs(int a) {
	visited[a] = true;
	for (int b : adj[a]) {
		if (B[b] == -1 || (!visited[B[b]] && dfs(B[b]))) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}
/*//////////////////////////////////////////////////////////////////
문제 해법		: 이분 매칭
결정적 깨달음		: 두 상어의 능력치가 동일한 경우, 두 상어 중 한 상어만 다른 상어로 간선을 이어준다. 두 상어 중 어느 상어가 다른 상어를 잡아먹는가는 결과값에 영향을 미치지 않는다.
시간복잡도		: 
오답 원인		: 1.
				  2.
*///////////////////////////////////////////////////////////////////