#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
int price[10001];
int minPrc;
vector<int> frnd[10001];
bool visited[10001];

void dfs(int x);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		cin >> price[i];

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		frnd[a].push_back(b);
		frnd[b].push_back(a);
	}
	//dfs
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			minPrc = 10001;
			dfs(i);
			ans += minPrc;
		}
	}

	if (ans <= k) cout << ans;
	else cout << "Oh no";

	return 0;
}

void dfs(int x) {
	visited[x] = true;
	minPrc = min(minPrc, price[x]);
	for (int i = 0; i < frnd[x].size(); i++) {
		if (visited[frnd[x][i]]) continue;
		dfs(frnd[x][i]);
	}
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: dfs
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. for문의 조건이 잘못됨
				  2. 
*/////////////////////////////////////////////////////////////////////