#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 100;
const int MAXV = MAX * MAX;

int N, labelR[MAX + 5][MAX + 5], labelC[MAX + 5][MAX + 5];
bool block[MAX + 5][MAX + 5], visited[MAXV + 5];
vector<int> adj[MAXV + 5];
int A[MAXV + 5], B[MAXV + 5];

void input();
void labeling();
void graph_modeling();
int bMatch();
bool dfs(int a);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();

	labeling();

	graph_modeling();

	int ans = bMatch();
	cout << ans << '\n';

	return 0;
}

void input() {
	int cnt;
	cin >> N >> cnt;

	while (cnt--) {
		int y, x;
		cin >> y >> x;
		block[y][x] = true;
	}
}

void labeling() {
	int rCnt = 0, cCnt = 0;
	for (int i = 1; i <= N; i++) {
		rCnt++;
		
		int y = i, x = 1;
		while (true) {
			if (N < y || N < x) break;
			if (block[y][x]) rCnt++;
			else labelR[y][x] = rCnt;
			y++, x++;
		}
	}
	for (int i = 2; i <= N; i++) {
		rCnt++;

		int y = 1, x = i;
		while (true) {
			if (N < y || N < x) break;
			if (block[y][x]) rCnt++;
			else labelR[y][x] = rCnt;
			y++, x++;
		}
	}

	for (int i = 1; i <= N; i++) {
		cCnt++;

		int y = i, x = N;
		while (true) {
			if (N < y || x < 1) break;
			if (block[y][x]) cCnt++;
			else labelC[y][x] = cCnt;
			y++, x--;
		}
	}
	for (int i = 2; i <= N; i++) {
		cCnt++;

		int y = 1, x = i;
		while (true) {
			if (N < y || x < 1) break;
			if (block[y][x]) cCnt++;
			else labelC[y][x] = cCnt;
			y++, x--;
		}
	}
}

void graph_modeling() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (block[y][x]) continue;
			adj[labelR[y][x]].push_back(labelC[y][x]);
		}
	}
}

int bMatch() {
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));

	int ret = 0;
	for (int i = 1; i < MAXV + 5; i++) {
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
시간복잡도		: 
오답 원인		: 1. 
				  2.
*///////////////////////////////////////////////////////////////////