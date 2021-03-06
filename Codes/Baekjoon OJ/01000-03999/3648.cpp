#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;

const int MAXV = 2 * 1e3;

int dfsn[MAXV + 5], dCnt, sNum[MAXV + 5], sCnt;
vector<int> adj[MAXV + 5];
bool finished[MAXV + 5];
stack<int> stk;

void reset();
inline int trans(int x);
int dfs(int now);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		reset();

		int N, M;
		cin >> N >> M;
		
		if (cin.eof()) break;

		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			adj[trans(-a)].push_back(trans(b));
			adj[trans(-b)].push_back(trans(a));
		}

		//1번 변수는 참이어야 함: (x1 v x1)
		adj[trans(-1)].push_back(trans(1));
		adj[trans(-1)].push_back(trans(1));

		//scc
		for (int v = 0; v < 2 * N; v++)
			if (dfsn[v] == -1) dfs(v);

		//충족 가능성 판별
		bool yes = true;

		for (int v = 0; v < 2 * N; v += 2) {
			if (sNum[v] == sNum[v + 1]) {
				yes = false;
				break;
			}
		}

		if (yes) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}

void reset() {
	memset(dfsn, -1, sizeof(dfsn));
	memset(sNum, 0, sizeof(sNum));
	dCnt = sCnt = 0;
	for (int i = 0; i < MAXV + 5; i++)
		adj[i].clear();
	memset(finished, 0, sizeof(finished));
}

inline int trans(int x) {
	return (x > 0) ? 2 * (x - 1) : 2 * (-x - 1) + 1;
}

int dfs(int now) {
	int ret = dfsn[now] = ++dCnt;

	stk.push(now);

	for (int next : adj[now]) {
		if (dfsn[next] == -1) ret = min(ret, dfs(next));
		else if (!finished[next]) ret = min(ret, dfsn[next]);
	}

	if (ret >= dfsn[now]) {
		while (true) {
			int t = stk.top();
			stk.pop();

			sNum[t] = sCnt;
			finished[t] = true;

			if (t == now) break;
		}
		sCnt++;
	}

	return ret;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 2-SAT
결정적 깨달음		: (x1 v x1) 식을 추가한다.
시간복잡도		: O(|V| + |E|)
오답 원인		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////