#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 100;

int N, A[MAX + 5], B[MAX + 5];
vector<int> adj[MAX + 5];
bool visited[MAX + 5];

void input();
int bMatch();
bool dfs(int a);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();

	int ans = bMatch();
	cout << ans << '\n';

	return 0;
}

void input() {
	int M;
	cin >> N >> M;

	while (M--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
}

int bMatch() {
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));

	int ret = 0;
	for (int i = 1; i <= N; i++) {
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
결정적 깨달음		:
시간복잡도		: O(NM)
오답 원인		: 1.
				  2.
*///////////////////////////////////////////////////////////////////