#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cassert>
using namespace std;

const int INF = 1e9 + 7;
const int MAX = 300;

int N, M, K, arr[MAX + 5][MAX + 5];
vector<int> adj[MAX + 5];
int A[MAX + 5], B[MAX + 5], dist[MAX + 5];
bool used[MAX + 5];

void input();
int bMatch(int L, int R);
int hopcroft();
void bInit();
void bfs();
bool dfs(int a);
void bfs2(int flag);
bool check(int flag, bool dir, int I);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();

	int ans = bMatch(0, 500001);
	cout << ans << '\n';

	bfs2(ans);

	return 0;
}

void input() {
	cin >> N >> M >> K;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			cin >> arr[y][x];
		}
	}
}

int bMatch(int L, int R) {
	bInit();

	int mid = (L + R) / 2;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (arr[y][x] > mid) adj[y].push_back(x);
		}
	}

	int total = hopcroft();

	//base case
	if (L == R) return L;

	if (total <= K) return bMatch(L, mid);
	else return bMatch(mid + 1, R);
}

int hopcroft() {
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));

	int ret = 0;
	while (true) {
		bfs();

		int flow = 0;
		for (int i = 1; i <= N; i++)
			if (!used[i] && dfs(i)) flow++;

		if (flow == 0) break;
		ret += flow;
	}
	return ret;
}

void bInit() {
	for (auto& i : adj) i.clear();
	memset(used, 0, sizeof(used));
}

void bfs() {
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (!used[i]) {
			dist[i] = 0;
			q.push(i);
		}
		else dist[i] = INF;
	}

	while (!q.empty()) {
		int a = q.front();
		q.pop();

		for (int b : adj[a]) {
			if (B[b] != -1 && dist[B[b]] == INF) {
				dist[B[b]] = dist[a] + 1;
				q.push(B[b]);
			}
		}
	}
}

bool dfs(int a) {
	for (int b : adj[a]) {
		if (B[b] == -1 || (dist[B[b]] == dist[a] + 1 && dfs(B[b]))) {
			used[a] = true;
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

void bfs2(int flag) {
	vector<bool> visitedA(MAX + 5), visitedB(MAX + 5);

	queue<int> q;

	for (int i = 1; i <= N; i++)
		if (!used[i]) q.push(i);

	int aCnt = 0, bCnt = 0;
	while (!q.empty()) {
		int a = q.front();
		q.pop();

		visitedA[a] = true;
		aCnt++;

		for (int b : adj[a]) {
			if (B[b] == -1 || visitedA[B[b]] || visitedB[b]) continue;
			visitedB[b] = true;
			bCnt++;
			q.push(B[b]);
		}
	}

	if (N - aCnt + bCnt < K) {
		for (int i = 1; i <= N; i++) {
			if (N - aCnt + bCnt == K) break;
			if (visitedA[i] && check(flag, true, i)) {
				visitedA[i] = false;
				aCnt--;
			}
		}
		for (int i = 1; i <= M; i++) {
			if (N - aCnt + bCnt == K) break;
			if (!visitedB[i] && check(flag, false, i)) {
				visitedB[i] = true;
				bCnt++;
			}
		}
	}

	assert(N - aCnt + bCnt == K);

	cout << N - aCnt << ' ';
	for (int i = 1; i <= N; i++)
		if (!visitedA[i]) cout << i << ' ';
	cout << '\n';

	cout << bCnt << ' ';
	for (int i = 1; i <= M; i++)
		if (visitedB[i]) cout << i << ' ';
}

bool check(int flag, bool dir, int I) {
	if (dir) {
		for (int x = 1; x <= M; x++)
			if (arr[I][x] == flag) return false;
		return true;
	}
	else {
		for (int y = 1; y <= N; y++)
			if (arr[y][I] == flag) return false;
		return true;
	}
}