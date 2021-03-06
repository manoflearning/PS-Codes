#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

const int MAX = 2000;
const int MOV[4][2] = { {1, 0},{0, 1},{-1,0},{0,-1} };

struct bb {
	int y;
	int x;
};
struct bbb {
	int y;
	int x;
	int t;
};

int n, k;
bb graph[MAX + 1][MAX + 1];
bool visited[MAX + 1][MAX + 1];

bb find(bb x);
void merge(bb a, bb b);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//reset
	memset(graph, -1, sizeof(graph));
	//
	cin >> n >> k;

	queue<bbb> q;
	for (int i = 0; i < k; i++) {
		int y, x;
		cin >> x >> y;
		q.push({ y, x, 0 });
		visited[y][x] = true;

		for (int l = 0; l < 4; l++) {
			int Y = y + MOV[l][0], X = x + MOV[l][1];
			if (Y < 1 || n < Y || X < 1 || n < X) continue;
			if (visited[Y][X]) merge({ y, x }, { Y, X });
		}
	}
	//큐 + 유니온 파인드
	int sum = k;
	//답이 0일 때 예외처리
	bb root = find({ q.front().y, q.front().x });
	if (graph[root.y][root.x].x == -sum) {
		cout << 0;
		return 0;
	}
	while (!q.empty()) {
		int y = q.front().y, x = q.front().x, t = q.front().t;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int Y = y + MOV[i][0], X = x + MOV[i][1];

			if (Y < 1 || n < Y || X < 1 || n < X) continue;
			if (visited[Y][X]) continue;

			sum++;
			visited[Y][X] = true;
			q.push({ Y,X, t + 1 });
			
			for (int l = 0; l < 4; l++) {
				int YY = Y + MOV[l][0], XX = X + MOV[l][1];
				if (YY < 1 || n < YY || XX < 1 || n < XX) continue;
				if (visited[YY][XX]) merge({ Y, X }, { YY, XX });
			}

			bb root = find({ Y, X });
			if (graph[root.y][root.x].x == -sum) {
				cout << t + 1;
				return 0;
			}
		}
	}

	return 0;
}

bb find(bb x) {
	bb& xParent = graph[x.y][x.x];
	if (xParent.x < 0) return x;
	bb root = find(xParent);
	xParent.y = root.y;
	xParent.x = root.x;
	return root;
}
void merge(bb a, bb b) {
	bb A = find(a), B = find(b);
	if (A.y == B.y && A.x == B.x) return;
	graph[A.y][A.x].x += graph[B.y][B.x].x;
	graph[B.y][B.x].y = A.y;
	graph[B.y][B.x].x = A.x;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: bfs + 유니온 파인드
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. bfs 구현할 때 pop 연산을 앞에 두자.
				  2. 입출력 시간 단축은 매번 하자. 입출력이 많을때만 하게 되면, 쉽게 까먹기 때문.
				  3. 답이 0일 때 예외처리를 못함
*/////////////////////////////////////////////////////////////////////