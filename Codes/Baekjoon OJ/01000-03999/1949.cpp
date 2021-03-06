#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 10000;
const bool bad = false, good = true;

vector<int> tree[MAX + 1];
int population[MAX + 1];

int dp[MAX + 1][2];

int mostPopulation(int node, int visited, bool isGood);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(dp, -1, sizeof(dp));

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> population[i];

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;

		tree[a].push_back(b), tree[b].push_back(a);
	}

	cout << mostPopulation(1, 0, bad);

	return 0;
}

int mostPopulation(int node, int visited, bool isGood) {
	if (isGood == good) {
		int& ret = dp[node][bad];
		//memoization
		if (ret != -1) return ret;

		ret = 0;
		for (int i = 0; i < tree[node].size(); i++) {
			if (tree[node][i] == visited) continue;

			ret += mostPopulation(tree[node][i], node, bad);
		}

		return ret;
	}
	else {
		int& retGood = dp[node][good], retBad = dp[node][bad];

		if (retGood == -1) {
			retGood = population[node];
			for (int i = 0; i < tree[node].size(); i++) {
				if (tree[node][i] == visited) continue;

				retGood += mostPopulation(tree[node][i], node, good);
			}
		}
		if (retBad == -1) {
			retBad = 0;
			for (int i = 0; i < tree[node].size(); i++) {
				if (tree[node][i] == visited) continue;

				retBad += mostPopulation(tree[node][i], node, bad);
			}
		}

		return max(retGood, retBad);
	}
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: dp, 트리
접근 방식		: 완전탐색 + dp, 3번 조건을 무시함.
결정적 깨달음		:
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////