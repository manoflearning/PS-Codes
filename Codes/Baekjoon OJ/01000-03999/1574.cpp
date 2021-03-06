#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 300;

int R, C, A[MAX + 5], B[MAX + 5];
bool isEmpty[MAX + 5][MAX + 5], visited[MAX + 5];
vector<int> adj[2 * MAX + 5];

void input();
void graph_modeling();
int bMatch();
bool dfs(int a);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();

	graph_modeling();

	int ans = bMatch();
	cout << ans << '\n';

	return 0;
}

void input() {
	int cnt;
	cin >> R >> C >> cnt;
	while (cnt--) {
		int a, b;
		cin >> a >> b;
		isEmpty[a][b] = true;
	}
}

void graph_modeling() {
	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			if (isEmpty[y][x]) continue;
			adj[y].push_back(x);
		}
	}
}

int bMatch() {
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));

	int ret = 0;
	for (int i = 1; i <= R; i++) {
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
결정적 깨달음		: 행 정점 그룹 A, 열 정점 그룹 B. 한 행에 룩을 놓는다는 것은, 하나의 열에는 더 이상 룩을 놓치 못한다는 의미.
시간복잡도		: O((R + C)RC)
오답 원인		: 1. 
				  2.
*///////////////////////////////////////////////////////////////////