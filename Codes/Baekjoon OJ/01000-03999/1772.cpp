#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 150;

int n, m, ans = 1e9;
vector<int> tree[MAX + 1], path;
int sz[MAX + 1], dp[MAX + 1][MAX + 1], dp2[MAX + 1][MAX + 1];
//dp[a][b]는 a를 루트로 하는 서브트리의 크기를 b로 만들기 위해 잘라야 하는 간선의 개수.

void dfs(int node, int last);
int dfs2(int flag, int siz);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(dp, -1, sizeof(dp));

	cin >> n >> m;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	//
	dfs(1, 0);

	cout << min(ans, dp[1][m]);

	return 0;
}

void dfs(int node, int last) {
	sz[node] = 1;
	vector<int> p;
	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i] == last) continue;
		dfs(tree[node][i], node);
		sz[node] += sz[tree[node][i]];
		p.push_back(tree[node][i]);
	}

	dp[node][0] = 1;
	dp[node][sz[node]] = 0;
	path = p;

	memset(dp2, -1, sizeof(dp2));

	for (int i = 1; i < sz[node]; i++)
		dp[node][i] = dfs2(0, i - 1);
	if (sz[node] >= m) ans = min(ans, dp[node][m] + 1);
}
//dfs2는 각각의 자식 노드를 루트로 하는 모든 서브트리에서, 가능한 모든 자르는 경우를 고려하는 함수. dp 테크닉을 통해 성능 향상.
int dfs2(int flag, int siz) {
	if (flag == path.size()) return (siz == 0) ? 0 : 1e9;

	int& ret = dp2[flag][siz];
	if (ret != -1) return ret;
	ret = 1e9;

	for (int i = 0; i <= min(siz, sz[path[flag]]); i++)
		ret = min(ret, dfs2(flag + 1, siz - i) + dp[path[flag]][i]);

	return ret;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: dp, 트리, dfs
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////