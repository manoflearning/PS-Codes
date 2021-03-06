#include <iostream>
#include <vector>
using namespace std;

int n;
int grid[100][100];

vector< vector<int> > dp;

bool gotoEnd(int y, int x);

int main() {
	int c;
	scanf("%d", &c);

	for (int test = 0; test < c; test++) {
		scanf("%d", &n);

		dp.resize(n, vector<int>(n, -1));

		for (int y = 0; y < n; y++)
			for (int x = 0; x < n; x++) {
				scanf("%d", &grid[y][x]);
			}

		if (gotoEnd(0, 0)) printf("YES\n");
		else printf("NO\n");

		dp.clear();
	}

	return 0;
}

bool gotoEnd(int y, int x) {
	//base case
	if (y >= n || x >= n) return false;
	if (y == n - 1 && x == n - 1) return true;
	//memoization
	if (dp[y][x] != -1) return dp[y][x];
	
	return dp[y][x] = gotoEnd(y + grid[y][x], x) || gotoEnd(y, x + grid[y][x]);
}
