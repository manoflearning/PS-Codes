#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1000;

int N, A[MAX + 5], B[MAX + 5];
vector<int> adj[MAX + 5];
bool visited[MAX + 5];

void init();
void input();
int bMatch();
bool dfs(int a);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;

	while (T--) {
		init();

		input();

		int ans = bMatch();
		cout << ans << '\n';
	}

	return 0;
}

void init() {
	for (int i = 0; i < MAX + 5; i++)
		adj[i].clear();
}

void input() {
	int M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
}

int bMatch() {
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));

	int ret = 0;
	for (int i = 0; i < N; i++) {
		memset(visited, 0, sizeof(visited));
		if (dfs(i)) ret++;
	}
	return ret;
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
결정적 깨달음		: 어떤 정점의 indegree나 outdegree는 2 이상일 수 없다 -> 이분 매칭이다.
시간복잡도		: 
오답 원인		: 1.
				  2.
*///////////////////////////////////////////////////////////////////