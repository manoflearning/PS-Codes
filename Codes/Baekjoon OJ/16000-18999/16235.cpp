#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int baby[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0},{1, 1} };

int n;
int grow[11][11], A[11][11];
vector<int> tree[11][11];

void spring_summer();
void fall();
void winter();

int main() {
	int m, k;
	cin >> n >> m >> k;

	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++) {
			cin >> A[y][x];
			grow[y][x] = 5;
		}
	//
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		tree[a][b].push_back(c);
	}

	for (int i = 0; i < k; i++) {
		spring_summer();
		fall();
		winter();
	}

	int ans = 0;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			ans += tree[y][x].size();
		}
	}

	cout << ans;

	return 0;
}

void spring_summer() {
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			sort(tree[y][x].begin(), tree[y][x].end());

			int grw = 0;

			bool check = true;
			int SIZ = tree[y][x].size();
			for (int i = 0; i < SIZ; i++) {
				if (check && grow[y][x] >= tree[y][x][i]) {
					grow[y][x] -= tree[y][x][i];
					tree[y][x][i]++;
				}
				else {
					check = false;
					grw += tree[y][x].back() / 2;
					tree[y][x].pop_back();
				}
			}

			grow[y][x] += grw;
		}
	}
}
void fall() {
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			for (int i = 0; i < tree[y][x].size(); i++) {
				if (tree[y][x][i] % 5 != 0) continue;

				for (int l = 0; l < 8; l++) {
					int Y = y + baby[l][0], X = x + baby[l][1];

					if (Y < 1 || n < Y) continue;
					if (X < 1 || n < X) continue;

					tree[Y][X].push_back(1);
				}
			}
		}
	}
}
void winter() {
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			grow[y][x] += A[y][x];
		}
	}
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 구현
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////