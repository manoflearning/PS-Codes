#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 50;
const int MAXV = 100;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

struct vd {
	int v, d;
};

int R, C; 
string arr[MAX + 5];
int Clabel[MAX + 5][MAX + 5], Plabel[MAX + 5][MAX + 5], Ccnt, Pcnt;
vector<vd> CP[MAXV + 5];
vector<int> adj[MAXV + 5];
int A[MAXV + 5], B[MAXV + 5];
bool visited[MAXV + 5];

void input();
bool check();
void bfs(int sy, int sx);
int bSearch(int L, int R);
void init();
int bMatch();
bool dfs(int a);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();

	if (!check()) return 0;

	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (arr[y][x] == 'C') bfs(y, x);
		}
	}

	int ans = bSearch(0, 1e5);
	if (ans != 1e5) cout << ans << '\n';
	else cout << -1 << '\n';

	return 0;
}

void input() {
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		cin >> arr[i];
}

bool check() {
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (arr[y][x] == 'C') Clabel[y][x] = ++Ccnt;
			else if (arr[y][x] == 'P') Plabel[y][x] = ++Pcnt;
		}
	}

	if (Ccnt == 0) {
		cout << 0 << '\n';
		return false;
	}

	return true;
}

void bfs(int sy, int sx) {
	vector<vector<bool>> visited(MAX + 5, vector<bool>(MAX + 5, false));

	struct yxd {
		int y, x, d;
	};

	queue<yxd> q;
	q.push({ sy, sx, 0 });
	visited[sy][sx] = true;

	while (!q.empty()) {
		int y = q.front().y, x = q.front().x, d = q.front().d;
		q.pop();

		if (arr[y][x] == 'P') {
			CP[Clabel[sy][sx]].push_back({ Plabel[y][x], d });
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (!(0 <= ny && ny < R && 0 <= nx && nx < C)) continue;
			if (arr[ny][nx] == 'X') continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = true;
			q.push({ ny, nx, d + 1 });
		}
	}
}

int bSearch(int L, int R) {
	if (L == R) return L;

	init();

	int mid = (L + R) / 2;
	
	for (int i = 1; i <= Ccnt; i++) {
		for (auto x : CP[i]) {
			if (x.d <= mid) adj[i].push_back(x.v);
			else break;
		}
	}
	
	int total = bMatch();
	
	if (total == Ccnt) return bSearch(L, mid);
	else return bSearch(mid + 1, R);
}

void init() {
	for (int i = 0; i < MAXV + 5; i++)
		adj[i].clear();
}

int bMatch() {
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));

	int ret = 0;
	for (int i = 1; i <= Ccnt; i++) {
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
문제 해법		: 이분 탐색, 이분 매칭
결정적 깨달음		: 시간을 기준으로 시간 내에 도착할 수 있는 주차장만 간선 형성
시간복잡도		: 
오답 원인		: 1. 벽을 고려하지 않음
				  2. 벽으로 인해 접근할 수 있는 주차장이 없는 경우를 고려하지 않음
				  3. 최장거리의 상한을 100이라고 생각함(실제로는 약 1250)
*///////////////////////////////////////////////////////////////////