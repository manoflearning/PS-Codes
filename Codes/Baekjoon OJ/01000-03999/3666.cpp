#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 7;
const int MAX = 100;
const int MAXV = 2 * MAX;

int N, st = 0, en = MAXV + 1, adjCnt, ourCnt;
string s[MAX + 5];
bool isEnemy[MAX + 5], isAdj[MAX + 5];
vector<int> adj[MAXV + 5];
int c[MAXV + 5][MAXV + 5], f[MAXV + 5][MAXV + 5], prv[MAXV + 5];

void init();
void scan();
inline int trans(int x);
int bsearch(int L, int R);
int max_flow();
void bfs();
int flow();

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;

	while (T--) {
		init();

		scan();
		
		int ans = bsearch(0, 100 * N);
		cout << ans << '\n';
	}

	return 0;
}

void init() {
	adjCnt = ourCnt = 0;
	memset(isEnemy, 0, sizeof(isEnemy));
	memset(isAdj, 0, sizeof(isAdj));
	for (int i = 0; i < MAXV + 5; i++)
		adj[i].clear();
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
}

void scan() {
	cin >> N;

	ourCnt = N;

	for (int i = 1; i <= N; i++) {
		cin >> c[st][i];

		if (c[st][i] != 0) {
			adj[st].push_back(i);
			adj[i].push_back(st);

			adj[i].push_back(trans(i));
			adj[trans(i)].push_back(i);
			c[i][trans(i)] = INF;
		}
		else {
			isEnemy[i] = true;
			ourCnt--;
		}
	}

	for (int i = 1; i <= N; i++) {
		cin >> s[i];
		for (int l = i + 1; l <= N; l++) {
			char x = s[i][l - 1];

			if (x == 'Y' && (isEnemy[i] ^ isEnemy[l])) {
				if (!isEnemy[i]) isAdj[i] = true;
				if (!isEnemy[l]) isAdj[l] = true;
			}
		}
	}
	
	for (int i = 1; i <= N; i++) {
		if (isAdj[i]) adjCnt++;
	}

	for (int i = 1; i <= N; i++) {
		for (int l = i + 1; l <= N; l++) {
			char x = s[i][l - 1];

			if (x == 'Y' && (!isEnemy[i] && !isEnemy[l])) {
				adj[i].push_back(trans(l));
				adj[trans(l)].push_back(i);
				c[i][trans(l)] = INF;

				adj[l].push_back(trans(i));
				adj[trans(i)].push_back(l);
				c[l][trans(i)] = INF;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (!isEnemy[i]) {
			adj[trans(i)].push_back(en);
			adj[en].push_back(trans(i));

			if (!isAdj[i]) c[trans(i)][en] = 1;
		}
	}
}

inline int trans(int x) {
	return MAX + x;
}

int bsearch(int L, int R) {
	if (L == R) return L;
	
	int mid = (L + R) / 2;

	for (int i = 1; i <= N; i++) {
		if (isAdj[i]) c[trans(i)][en] = mid + 1;
	}

	int total = max_flow();

	if (total == adjCnt * (mid + 1) + (ourCnt - adjCnt) * 1) return bsearch(mid + 1, R);
	else return bsearch(L, mid);
}

int max_flow() {
	memset(f, 0, sizeof(f));

	int ret = 0;
	while (true) {
		bfs();

		if (prv[en] == -1) break;

		ret += flow();
	}
	return ret;
}

void bfs() {
	memset(prv, -1, sizeof(prv));

	queue<int> q;
	q.push(st);
	prv[st] = 0;

	while (!q.empty() && prv[en] == -1) {
		int now = q.front();
		q.pop();

		for (int next : adj[now]) {
			if (prv[next] == -1 && c[now][next] - f[now][next] > 0) {
				prv[next] = now;
				q.push(next);
			}
		}
	}
}

int flow() {
	int n = en, block = INF;
	while (n != st) {
		block = min(block, c[prv[n]][n] - f[prv[n]][n]);
		n = prv[n];
	}
	n = en;
	while (n != st) {
		f[prv[n]][n] += block;
		f[n][prv[n]] -= block;
		n = prv[n];
	}
	return block;
}
/*//////////////////////////////////////////////////////////////////
문제 해법		: 네트워크 유량
결정적 깨달음		:
시간복잡도		: 
오답 원인		: 1. 몇몇 케이스에서 적과 인접한 영토의 개수를 중복해서 셈
				  2.
*///////////////////////////////////////////////////////////////////