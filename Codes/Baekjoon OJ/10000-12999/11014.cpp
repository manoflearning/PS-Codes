#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 80, MAXV = MAX * MAX;
const int dy[] = { -1, -1, 0, 0, 1, 1 };
const int dx[] = { -1, 1, -1, 1, -1, 1 };

int R, C, labelA[MAX + 5][MAX + 5], labelB[MAX + 5][MAX + 5], lCnt;
string arr[MAX + 5];
vector<int> adj[MAXV + 5];
int A[MAXV + 5], B[2 * MAXV + 5];
bool visited[MAXV + 5];

void init();
void input();
void graph_modeling();
int bMatch();
bool dfs(int a);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;

	while (T--) {
		init();

		input();

		graph_modeling();

		int total = bMatch();
		cout << lCnt - total << '\n';
	}

	return 0;
}

void init() {
	for (int i = 0; i < MAXV + 5; i++)
		adj[i].clear();
}

void input() {
	cin >> R >> C;
	for (int y = 0; y < R; y++) cin >> arr[y];
}

void graph_modeling() {
	//정점 번호 붙이기
	lCnt = 0;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x += 2) {
			if (arr[y][x] == '.') labelA[y][x] = lCnt++;
		}
	}
	for (int y = 0; y < R; y++) {
		for (int x = 1; x < C; x += 2) {
			if (arr[y][x] == '.') labelB[y][x] = lCnt++;
		}
	}

	//간선 형성
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x += 2) {
			if (arr[y][x] == 'x') continue;
			for (int i = 0; i < 6; i++) {
				int ny = y + dy[i], nx = x + dx[i];
				if (ny < 0 || R <= ny || nx < 0 || C <= nx) continue;
				if (arr[ny][nx] == 'x') continue;
				adj[labelA[y][x]].push_back(labelB[ny][nx]);
			}
		}
	}
}

int bMatch() {
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));

	int ret = 0;
	for (int i = 0; i < MAXV + 5; i++) {
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