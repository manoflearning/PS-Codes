#include <iostream>
#define pii pair<int, int>
using namespace std;

const int MAX = 250;
const int dy[] = { 0, 1, 0, -1 };
const int dx[] = { 1, 0, -1, 0 };

int R, C;
char arr[MAX + 5][MAX + 5];
bool visited[MAX + 5][MAX + 5];

pii dfs(int y, int x);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> R >> C;

	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			cin >> arr[y][x];
		}
	}

	pii ans = { 0, 0 };
	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			if (arr[y][x] != '#' && !visited[y][x]) {
				pii sw = dfs(y, x);
				
				if (sw.first > sw.second) ans.first += sw.first;
				else ans.second += sw.second;
			}
		}
	}

	cout << ans.first << ' ' << ans.second << '\n';

	return 0;
}

pii dfs(int y, int x) {
	visited[y][x] = true;
	
	pii ret = { 0, 0 };
	
	if (arr[y][x] == 'o') ret.first++;
	else if (arr[y][x] == 'v') ret.second++;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		
		if (ny < 1 || R < ny || nx < 1 || C < nx) continue;
		if (visited[ny][nx]) continue;
		if (arr[ny][nx] == '#') continue;

		pii x = dfs(ny, nx);
		ret.first += x.first;
		ret.second += x.second;
	}

	return ret;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: dfs
결정적 깨달음		:
시간복잡도		: O(RC)
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////