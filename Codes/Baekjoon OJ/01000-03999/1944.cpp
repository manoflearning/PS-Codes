#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MV[4][2] = { {0, 1},{1, 0},{-1, 0},{0, -1} };

struct yx {
	int y, x;
};
struct nnd {
	int n1, n2, d;
};

int N, M, dist[55][55][55][55], p[255];
char miro[55][55];
vector<yx> V;
vector<nnd> E;

bool cmp(nnd a, nnd b) {
	return a.d < b.d;
}

void bfs(yx st);
int find(int x);
void merge(int a, int b);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	memset(p, -1, sizeof(p));

	cin >> N >> M;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> miro[y][x];
			if (miro[y][x] == 'S' || miro[y][x] == 'K')
				V.push_back({ y, x });
		}
	}

	for (int i = 0; i < V.size(); i++) {
		bfs(V[i]);
	}

	for (int u = 0; u < V.size(); u++) {
		for (int v = u + 1; v < V.size(); v++) {
			E.push_back({ u, v, dist[V[u].y][V[u].x][V[v].y][V[v].x] });
			
			if (E.back().d == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	sort(E.begin(), E.end(), cmp);

	int cost = 0;
	for (int i = 0; i < E.size(); i++) {
		if (find(E[i].n1) == find(E[i].n2)) continue;
		cost += E[i].d;
		merge(E[i].n1, E[i].n2);
	}

	cout << cost;

	return 0;
}

void bfs(yx st) {
	bool visited[55][55];
	memset(visited, 0, sizeof(visited));
	
	struct yxd {
		int y, x, d;
	};

	queue<yxd> q;
	q.push({ st.y, st.x, 0 });
	visited[st.y][st.x] = true;

	while (!q.empty()) {
		int y = q.front().y, x = q.front().x, d = q.front().d;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int Y = y + MV[i][0], X = x + MV[i][1];

			if (visited[Y][X] || miro[Y][X] == '1') continue;

			visited[Y][X] = true;
			if (miro[Y][X] == 'S' || miro[Y][X] == 'K')
				dist[st.y][st.x][Y][X] = d + 1;
			q.push({ Y, X, d + 1 });
		}
	}
}
int find(int x) {
	if (p[x] < 0) return x;
	p[x] = find(p[x]);
	return p[x];
}
void merge(int a, int b) {
	int A = find(a), B = find(b);
	if (A == B) return;
	p[A] += p[B];
	p[B] = A;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 크루스칼 알고리즘
결정적 깨달음		: 
시간복잡도		: O(m^2lgm)
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////