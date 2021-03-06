#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 10000;

int n, value[MAX + 1];
vector<int> tree[MAX + 1];
int dp[MAX + 1][2];

vector<int> ans;

int find_max(int node, int last, bool ON);
void find_path(int node, int last, bool ON);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	memset(dp, -1, sizeof(dp));
	//
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> value[i];

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	//
	cout << find_max(1, 0, false) << '\n';

	find_path(1, 0, false);

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	
	return 0;
}

int find_max(int node, int last, bool ON) {
	int& ret1 = dp[node][0], & ret2 = dp[node][1];

	if (ret1 == -1) {
		ret1 = 0;
		for (int i = 0; i < tree[node].size(); i++) {
			if (tree[node][i] == last) continue;
			ret1 += find_max(tree[node][i], node, false);
		}
	}

	if (ret2 == -1 && !ON) {
		ret2 = value[node];
		for (int i = 0; i < tree[node].size(); i++) {
			if (tree[node][i] == last) continue;
			ret2 += find_max(tree[node][i], node, true);
		}
	}

	if (ON) return ret1;
	else return max(ret1, ret2);
}
void find_path(int node, int last, bool ON) {
	if (!ON) {
		if (dp[node][0] < dp[node][1]) {
			ans.push_back(node);
			for (int i = 0; i < tree[node].size(); i++) {
				if (tree[node][i] == last) continue;
				find_path(tree[node][i], node, true);
			}
		}
		else {
			for (int i = 0; i < tree[node].size(); i++) {
				if (tree[node][i] == last) continue;
				find_path(tree[node][i], node, false);
			}
		}
	}
	else {
		for (int i = 0; i < tree[node].size(); i++) {
			if (tree[node][i] == last) continue;
			find_path(tree[node][i], node, false);
		}
	}
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: dp, 트리
접근 방식		: dp 역추적
결정적 깨달음		: 
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////