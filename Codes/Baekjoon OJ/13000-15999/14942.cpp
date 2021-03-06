#include <iostream>
#include <vector>
#define ll long long
using namespace std;

const int MAX = 1e5, MAXD = 13;

ll ene[MAX + 1];
ll f[MAX + 1][MAXD + 1], need[MAX + 1][MAXD + 1];
vector<pair<int, int>> tree[MAX + 1];

void DFS(int node, int last);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> ene[i];
	//
	for (int i = 0; i < n - 1; i++) {
		int a, b, x;
		cin >> a >> b >> x;
		tree[a].push_back({ b, x });
		tree[b].push_back({ a, x });
	}

	f[1][0] = 1;
	DFS(1, 0);
	//
	for (int j = 1; j <= MAXD; j++) {
		for (int i = 1; i <= n; i++) {
			f[i][j] = f[f[i][j - 1]][j - 1];
			need[i][j] = need[f[i][j - 1]][j - 1] + need[i][j - 1];
		}
	}
	//
	for (int i = 1; i <= n; i++) {
		int x = i;
		for (int j = MAXD; j >= 0; j--) {
			if (ene[i] >= need[x][j]) {
				ene[i] -= need[x][j];
				x = f[x][j];
				j = MAXD + 1;
			}
			if (x == 1) break;
		}

		cout << x << '\n';
	}

	return 0;
}

void DFS(int node, int last) {
	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i].first == last) continue;

		f[tree[node][i].first][0] = node;
		need[tree[node][i].first][0] = tree[node][i].second;
		DFS(tree[node][i].first, node);
	}
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 희소 테이블
접근 방식		:
결정적 깨달음		:
오답 원인		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////