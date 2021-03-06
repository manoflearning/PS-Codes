#include <iostream>
#include <vector>
#include <cstring>
#define pii pair<int, int>
using namespace std;

const int MAX = 100;
const int MAXV = MAX * MAX;

int N, A[MAXV + 5], B[MAXV + 5], rowCnt;
string arr[MAX + 5];
vector<int> adj[MAXV + 5];
bool visited[MAXV + 5];
int label[MAX + 5][MAX + 5];

void input();
void graph_modeling();
inline int trans(int y, int x);
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
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
}

void graph_modeling() {
	bool first;
	
	for (int y = 0; y < N; y++) {
		first = true;
		for (int x = 0; x < N; x++) {
			if (arr[y][x] == '.') {
				if (first) {
					first = false;
					rowCnt++;
				}
				label[y][x] = rowCnt;
			}
			else first = true;
		}
	}

	int colCnt = 0;
	for (int x = 0; x < N; x++) {
		first = true;
		for (int y = 0; y < N; y++) {
			if (arr[y][x] == '.') {
				if (first) {
					first = false;
					colCnt++;
				}
				adj[label[y][x]].push_back(colCnt);
			}
			else first = true;
		}
	}
}

inline int trans(int y, int x) {
	return y * MAX + x;
}

int bMatch() {
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));

	int ret = 0;
	for (int i = 1; i <= rowCnt; i++) {
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
문제 해법		: 이분 탐색
결정적 깨달음		: 연결된 행을 하나의 정점으로 연결된 열을 하나의 정점으로 보아, 칸을 공유하는 연결된 행과 열을 간선으로 잇는다.
시간복잡도		: 
오답 원인		: 1. 
				  2. 
*///////////////////////////////////////////////////////////////////