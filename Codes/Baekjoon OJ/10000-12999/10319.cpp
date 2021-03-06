#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
using namespace std;

const int INF = 1e9 + 7;
const int MAX = 1000, MAXS = 100;
const int MAXV = (MAXS + 1) * MAX;

struct vcfr {
	int v, c, f, rev;
};

int N, G, S;
int st = 0, en = MAXV + 1;
vector<vcfr> adj[MAXV + 5];
pii prv[MAXV + 5];

void init();
void scan();
inline int trans(int x, int s);
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

		int ans = max_flow();
		cout << ans << '\n';
	}

	return 0;
}

void init() {
	for (int i = 0; i < MAXV + 5; i++)
		adj[i].clear();
}

void scan() {
	cin >> N;

	int flag;
	cin >> flag >> G >> S;

	//소스와 0초의 시작장소 노드를 연결, 용량은 G
	adj[st].push_back({ trans(flag, 0), G, 0, (int)adj[trans(flag, 0)].size() });
	adj[trans(flag, 0)].push_back({ st, 0, 0, (int)adj[st].size() - 1 });

	//S초의 병원 노드와 싱크를 연결, 용량은 INF
	int M;  cin >> M;
	for (int i = 0; i < M; i++) {
		int x; cin >> x;
		adj[trans(x, S)].push_back({ en, INF, 0, (int)adj[en].size() });
		adj[en].push_back({ trans(x, S), 0, 0, (int)adj[trans(x, S)].size() - 1 });
	}

	//같은 장소를 단위시간에 따라 연결, 용량은 INF
	for (int i = 1; i <= N; i++) {
		for (int s = 0; s <= S - 1; s++) {
			adj[trans(i, s)].push_back({ trans(i, s + 1), INF, 0, (int)adj[trans(i, s + 1)].size() });
			adj[trans(i, s + 1)].push_back({ trans(i, s), 0, 0, (int)adj[trans(i, s)].size() - 1 });
		}
	}

	//도로를 단위시간별로 연결
	int R; cin >> R;
	for (int i = 0; i < R; i++) {
		int a, b, p, t;
		cin >> a >> b >> p >> t;
		for (int s = 0; s <= S - t; s++) {
			adj[trans(a, s)].push_back({ trans(b, s + t), p, 0, (int)adj[trans(b, s + t)].size() });
			adj[trans(b, s + t)].push_back({ trans(a, s), 0, 0, (int)adj[trans(a, s)].size() - 1 });
		}
	}
}

inline int trans(int x, int s) {
	return s * MAX + x;
}

int max_flow() {
	int ret = 0;
	while (true) {
		bfs();

		if (prv[en].first == -1) break;
		
		ret += flow();
	}
	return ret;
}

void bfs() {
	memset(prv, -1, sizeof(prv));

	queue<int> q;
	q.push(st);
	prv[st].first = 0;

	while (!q.empty() && prv[en].first == -1) {
		int now = q.front();
		q.pop();
		
		for (int i = 0; i < adj[now].size(); i++) {
			auto next = adj[now][i];
			
			if (prv[next.v].first == -1 && next.c - next.f > 0) {
				prv[next.v].first = now;
				prv[next.v].second = i;
				q.push(next.v);
			}
		}
	}
}

int flow() {
	int n = en, block = INF;
	while (n != st) {
		auto& e = adj[prv[n].first][prv[n].second];
		block = min(block, e.c - e.f);
		n = prv[n].first;
	}
	n = en;
	while (n != st) {
		auto& e = adj[prv[n].first][prv[n].second];
		auto& rev_e = adj[e.v][e.rev];
		e.f += block;
		rev_e.f -= block;
		n = prv[n].first;
	}
	return block;
}
/*//////////////////////////////////////////////////////////////////
문제 해법		: 네트워크 유량
결정적 깨달음		: 간선에 역방향 간선 정보를 저장하여, 인접리스트로 용량과 유량을 구현할 수 있다. 장소를 단위시간별로 구분하여 각각 정점에 대응한다.
시간복잡도		:
오답 원인		: 1.
				  2.
*///////////////////////////////////////////////////////////////////