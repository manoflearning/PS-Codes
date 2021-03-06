#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;

const int MAX = 1e5;

bool isOpened[MAX + 5], finished[2 * MAX + 5];
vector<int> connected[MAX + 5], adj[2 * MAX + 5];
int dfsn[2 * MAX + 5], dCnt, sNum[2 * MAX + 5], sCnt;
stack<int> stk;

inline int trans(int x);
int dfs(int now);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(dfsn, -1, sizeof(dfsn));

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		cin >> isOpened[i];

	for (int i = 1; i <= M; i++) {
		int cnt; cin >> cnt;
		while (cnt--) {
			int x; cin >> x;
			connected[x].push_back(i);
		}
	}

	for (int i = 1; i <= N; i++) {
		int a = connected[i][0], b = connected[i][1];
		if (isOpened[i]) {
			adj[trans(a)].push_back(trans(b));
			adj[trans(b)].push_back(trans(a));
			adj[trans(-a)].push_back(trans(-b));
			adj[trans(-b)].push_back(trans(-a));
		}
		else {
			adj[trans(-a)].push_back(trans(b));
			adj[trans(-b)].push_back(trans(a));
			adj[trans(a)].push_back(trans(-b));
			adj[trans(b)].push_back(trans(-a));
		}
	}

	//scc
	for (int i = 0; i < 2 * M; i++)
		if (dfsn[i] == -1) dfs(i);

	//
	bool yes = true;
	for (int i = 0; i < 2 * M; i += 2) {
		if (sNum[i] == sNum[i + 1]) {
			yes = false;
			break;
		}
	}

	if (yes) cout << 1;
	else cout << 0;

	return 0;
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
문제 해법		: 2-SAT 응용
결정적 깨달음		: 
시간복잡도		: 
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////