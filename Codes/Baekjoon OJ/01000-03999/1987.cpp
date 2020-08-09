#include <iostream>
#include <algorithm>
using namespace std;

int r, c;
char b[21][21];
bool visited[26];

int dfs(int y, int x);

int main() {
	cin >> r >> c;

	for (int y = 1; y <= r; y++)
		for (int x = 1; x <= c; x++)
			cin >> b[y][x];
	
	cout << dfs(1, 1);

	return 0;
}

int dfs(int y, int x) {
	visited[b[y][x] - 'A'] = true;
	
	int ret = 0;

	if (y > 1 && !visited[b[y - 1][x] - 'A'])
		ret = max(ret, dfs(y - 1, x));
	if (y < r && !visited[b[y + 1][x] - 'A'])
		ret = max(ret, dfs(y + 1, x));
	if (x > 1 && !visited[b[y][x - 1] - 'A'])
		ret = max(ret, dfs(y, x - 1));
	if (x < c && !visited[b[y][x + 1] - 'A'])
		ret = max(ret, dfs(y, x + 1));
	
	visited[b[y][x] - 'A'] = false;

	return ret += 1;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: dfs�� ����
���� ���		: visited �迭�� ����� ��ǥ ���, ����� ������ ����. �Ϲ����� dfs�δ� �ִܰŸ� Ȥ�� ����Ÿ��� ���� �� �����Ƿ� visited �迭�� dfs�Լ��� ���� ��ȯ�ϱ� ���� false�� ����.
������ ������		: 
���� ����		: 1. dp�� ��ǥ������ �������� �����ϴ� ���� �߸���. ���� �κ� ������ �ƴϱ� ����.
				  2.
*/////////////////////////////////////////////////////////////////////