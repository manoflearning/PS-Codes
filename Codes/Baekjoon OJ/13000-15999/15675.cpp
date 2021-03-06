#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int MAXV = 4 * 1e3;

int Y, X, dfsn[MAXV + 5], dCnt, sNum[MAXV + 5], sCnt;
vector<int> adj[MAXV + 5];
bool finished[MAXV + 5];
stack<int> stk;

int trans(int y, int x, bool isY, bool on);
int dfs(int now);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> Y >> X;

	for (int y = 1; y <= Y; y++) {
		for (int x = 1; x <= X; x++) {
			char c; cin >> c;

			if (c == '#') {
				//(y ⇒ x) ∧ (x ⇒ y) ∧ (￢y ⇒ ￢x) ∧ (￢x ⇒ ￢y)
				adj[trans(y, x, true, true)].push_back(trans(y, x, false, true));
				adj[trans(y, x, false, true)].push_back(trans(y, x, true, true));
				adj[trans(y, x, true, false)].push_back(trans(y, x, false, false));
				adj[trans(y, x, false, false)].push_back(trans(y, x, true, false));
			}
			else if (c == '*') {
				//(￢y ⇒ x) ∧ (￢x ⇒ y) ∧ (y ⇒ ￢x) ∧ (x ⇒ ￢y)
				adj[trans(y, x, true, false)].push_back(trans(y, x, false, true));
				adj[trans(y, x, false, false)].push_back(trans(y, x, true, true));
				adj[trans(y, x, true, true)].push_back(trans(y, x, false, false));
				adj[trans(y, x, false, true)].push_back(trans(y, x, true, false));
			}
		}
	}
	
	//scc
	memset(dfsn, -1, sizeof(dfsn));
	
	int N = 2 * (Y + X);
	for (int i = 0; i < N; i++)
		if (dfsn[i] == -1) dfs(i);

	//
	bool yes = true;
	for (int i = 0; i < N; i += 2) {
		if (sNum[i] == sNum[i + 1]) {
			yes = false;
			break;
		}
	}

	if (yes) cout << 1;
	else cout << 0;

	return 0;
}

int trans(int y, int x, bool isY, bool on) {
	int ret = isY ? y : Y + x;
	return on ? 2 * (ret - 1) : 2 * (ret - 1) + 1;
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
결정적 깨달음		: 
시간복잡도		: O(XY)
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////