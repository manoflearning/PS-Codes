#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n;
char b[101][101];
bool visited[101][101];

void dfs(int y, int x);
void RGdfs(int y, int x);

int main() {
	cin >> n;

	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++) {
			cin >> b[y][x];
		}

	int ans = 0, RGans = 0;
	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++) {
			if (!visited[y][x]) {
				ans++;
				dfs(y, x);
			}
		}

	memset(visited, 0, sizeof(visited));

	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++) {
			if (!visited[y][x]) {
				RGans++;
				RGdfs(y, x);
			}
		}

	cout << ans << ' ' << RGans;

	return 0;
}

void dfs(int y, int x) {
	visited[y][x] = true;

	if (y > 1 && b[y][x] == b[y - 1][x] && !visited[y - 1][x])
		dfs(y - 1, x);
	if (y < n && b[y][x] == b[y + 1][x] && !visited[y + 1][x])
		dfs(y + 1, x);
	if (x > 1 && b[y][x] == b[y][x - 1] && !visited[y][x - 1])
		dfs(y, x - 1);
	if (x < n && b[y][x] == b[y][x + 1] && !visited[y][x + 1])
		dfs(y, x + 1);
}
void RGdfs(int y, int x) {
	visited[y][x] = true;

	string RGB;
	if (b[y][x] == 'R' || b[y][x] == 'G') {
		RGB.push_back('R');
		RGB.push_back('G');
	}
	else RGB.push_back('B');

	if (y > 1 && RGB.find(b[y - 1][x]) != string::npos && !visited[y - 1][x])
		RGdfs(y - 1, x);
	if (y < n && RGB.find(b[y + 1][x]) != string::npos && !visited[y + 1][x])
		RGdfs(y + 1, x);
	if (x > 1 && RGB.find(b[y][x - 1]) != string::npos && !visited[y][x - 1])
		RGdfs(y, x - 1);
	if (x < n && RGB.find(b[y][x + 1]) != string::npos && !visited[y][x + 1])
		RGdfs(y, x + 1);
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: dfs 응용
접근 방식		: string::npos와 string의 find함수를 활용해서 노드의 연결 여부 검사
결정적 깨달음		:
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////