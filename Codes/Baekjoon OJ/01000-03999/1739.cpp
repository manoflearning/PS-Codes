#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int MAXV = 2 * 2 * 1e3;

int dfsn[MAXV + 5], dCnt, sNum[MAXV + 5], sCnt;
vector<int> adj[MAXV + 5];
bool finished[MAXV + 5];
stack<int> stk;

void reset();
inline int trans(int c);
int dfs(int now);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;

	while (T--) {
		reset();

		int X, Y, K;
		cin >> X >> Y >> K;

		for (int i = 0; i < K; i++) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			
			y1 += X, y2 += X;
			//방향 설정
			if (x1 > x2 && y1 > y2) {
				y1 = -y1, y2 = -y2;
				x1 = -x1, x2 = -x2;
			}
			else if (x1 > x2) {
				y1 = -y1, y2 = -y2;
			}
			else if (y1 > y2) {
				x1 = -x1, x2 = -x2;
			}

			//간선 추가
			if (x1 == x2 && y1 == y2) continue;
			else if (x1 == x2) {
				//(x1 ∨ x1)
				adj[trans(-x1)].push_back(trans(x1));
				adj[trans(-x1)].push_back(trans(x1));
			}
			else if (y1 == y2) {
				//(y1 ∨ y1)
				adj[trans(-y1)].push_back(trans(y1));
				adj[trans(-y1)].push_back(trans(y1));
			}
			else {
				//(x1 ∧ y2) ∨ (x2 ∧ y1)
				//(x1 ∨ x2) ∧ (x1 ∨ y1) ∧ (y2 ∨ x2) ∧ (y2 ∨ y1)
				adj[trans(-x1)].push_back(trans(x2));
				adj[trans(-x2)].push_back(trans(x1));

				adj[trans(-x1)].push_back(trans(y1));
				adj[trans(-y1)].push_back(trans(x1));

				adj[trans(-y2)].push_back(trans(x2));
				adj[trans(-x2)].push_back(trans(y2));

				adj[trans(-y2)].push_back(trans(y1));
				adj[trans(-y1)].push_back(trans(y2));
			}
		}

		//scc
		for (int i = 0; i < 2 * (X + Y); i++)
			if (dfsn[i] == -1) dfs(i);

		//충족 가능성 판별
		bool Yes = true;
		for (int i = 0; i < 2 * (X + Y); i += 2) {
			if (sNum[i] == sNum[i + 1]) {
				Yes = false;
				break;
			}
		}

		if (Yes) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}

void reset() {
	memset(dfsn, -1, sizeof(dfsn));
	memset(sNum, -1, sizeof(sNum));
	dCnt = sCnt = 0;
	for (int i = 0; i < MAXV; i++)
		adj[i].clear();
	memset(finished, 0, sizeof(finished));
}

inline int trans(int c) {
	return (c > 0) ? 2 * (c - 1) : 2 * (-c - 1) + 1;
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
접근 방식		:
결정적 깨달음		:
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////