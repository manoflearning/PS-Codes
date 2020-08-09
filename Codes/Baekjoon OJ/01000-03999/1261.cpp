#include <iostream>
#include <queue>
#include <climits>
using namespace std;

const int MAX = 100;

int m, n;
int miro[MAX + 1][MAX + 1];
int path[MAX + 1][MAX + 1];

struct wall {
	int x;
	int y;
	int value;
};

struct comp {
	bool operator()(wall a, wall b) {
		return a.value > b.value;
	}
};

void shortestPath();

int main() {
	cin >> m >> n;

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			char v;
			cin >> v;
			
			if (v == '1') miro[y][x] = 1;
			else miro[y][x] = 0;

			path[y][x] = INT_MAX;
		}
	}

	shortestPath();

	return 0;
}

void shortestPath() {
	priority_queue<wall, vector<wall>, comp> pq;

	pq.push({ 1, 1, 0 });

	while (!pq.empty()) {
		int x = pq.top().x, y = pq.top().y, v = pq.top().value;

		if (x == m && y == n) {
			cout << v;
			return;
		}

		if (v < path[y][x]) {
			path[y][x] = v;

			if (y > 1) pq.push({ x, y - 1, v + miro[y - 1][x] });
			if (y < n) pq.push({ x, y + 1, v + miro[y + 1][x] });
			if (x > 1) pq.push({ x - 1, y, v + miro[y][x - 1] });
			if (x < m) pq.push({ x + 1, y, v + miro[y][x + 1] });
		}

		pq.pop();
	}
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: ���ͽ�Ʈ�� �˰�����
���� ���		: 
������ ������		: priority_queue�� ���Լ��� ������ �����ε��� ���� ������ �� �ִ�.
���� ����		: 1. ������ �����ε� �� ���Լ��� �Ųٷ� ������. �ּ� �켱���� ť�� �ƴ�, �ִ� �켱���� ť�� ������.
				  2.
*/////////////////////////////////////////////////////////////////////