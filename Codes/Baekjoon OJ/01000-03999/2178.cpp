#include <iostream>
#include <queue>
using namespace std;

int n, m;
bool path[101][101];
bool visited[101][101];

int bfs(int y, int x);

int main() {
	cin >> n >> m;

	for (int y = 1; y <= n; y++) {
		string v;
		cin >> v;

		for (int x = 1; x <= m; x++)
			if (v[x - 1] == '1') path[y][x] = true;
	}

	cout << bfs(1, 1);

	return 0;
}

int bfs(int y, int x) {
	struct b{
		int y;
		int x;
		int value;
	};
	
	queue<b> q;
	q.push({ y, x, 1 });
	visited[y][x] = true;

	while (!q.empty()) {
		int Y = q.front().y, X = q.front().x, V = q.front().value;

		if (Y > 1 && path[Y - 1][X] && !visited[Y - 1][X]) {
			q.push({ Y - 1, X, V + 1 });
			visited[Y - 1][X] = true;
		}
		if (Y < 100 && path[Y + 1][X] && !visited[Y + 1][X]) {
			q.push({ Y + 1, X, V + 1 });
			visited[Y + 1][X] = true;
		}
		if (X > 1 && path[Y][X - 1] && !visited[Y][X - 1]) {
			q.push({ Y, X - 1, V + 1 });
			visited[Y][X - 1] = true;
		}
		if (X < 100 && path[Y][X + 1] && !visited[Y][X + 1]) {
			q.push({ Y, X + 1, V + 1 });
			visited[Y][X + 1] = true;
		}

		if (Y == n && X == m) return V;
		q.pop();
	}
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: bfs
���� ���		: ť�� �Ÿ����� ����.
������ ������		: 
���� ����		: 1. dfs�� �ִܰŸ��� ���ϴ� �������� �������� ����
				  2.
*/////////////////////////////////////////////////////////////////////