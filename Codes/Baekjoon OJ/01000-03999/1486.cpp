#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 51;
const int INF = 1e9 + 7;
const int MV[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

struct yxhd {
	int y, x, h, d;
};
struct cmp {
	bool operator() (yxhd a, yxhd b) {
		return a.d > b.d;
	}
};

int Y, X, T, D, M[MAX + 5][MAX + 5];
int adj[MAX + 5][MAX + 5][4], dist[MAX + 5][MAX + 5][MAX + 5];

int max_height();
inline int trans(char now);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < MAX + 5; i++)
		for (int l = 0; l < MAX + 5; l++)
			fill(dist[i][l], dist[i][l] + MAX + 5, INF);
	
	//시작
	cin >> Y >> X >> T >> D;

	for (int y = 1; y <= Y; y++) {
		for (int x = 1; x <= X; x++) {
			char n; cin >> n;
			M[y][x] = trans(n);
		}
	}

	//가중치 인접 행렬로 계산 및 저장
	for (int y = 1; y <= Y; y++) {
		for (int x = 1; x <= X; x++) {
			for (int i = 0; i < 4; i++) {
				int ny = y + MV[i][0], nx = x + MV[i][1];
				if (ny < 1 || Y < ny || nx < 1 || X < nx) continue;
				
				int hd = M[ny][nx] - M[y][x];
				if (hd <= 0) adj[y][x][i] = 1;
				else adj[y][x][i] = hd * hd;
			}
		}
	}

	max_height();

	for (int h = MAX; h >= 0; h--) {
		if (dist[1][1][h] <= D) {
			cout << h;
			break;
		}
	}

	return 0;
}

int max_height() {
	priority_queue<yxhd, vector<yxhd>, cmp> pq;
	pq.push({ 1,1,M[1][1],0 });
	dist[1][1][M[1][1]] = 0;

	int ret = 0;

	while (!pq.empty()) {
		int y = pq.top().y, x = pq.top().x, h = pq.top().h, d = pq.top().d;
		pq.pop();
		
		if (dist[y][x][h] < d) continue;

		ret = max(ret, h);
		
		for (int i = 0; i < 4; i++) {
			int ny = y + MV[i][0], nx = x + MV[i][1];

			if (ny < 1 || Y < ny || nx < 1 || X < nx) continue;
			if (fabs(M[ny][nx] - M[y][x]) > T) continue;

			int nh = max(h, M[ny][nx]);
			
			int& nd = dist[ny][nx][nh];
			if (nd > d + adj[y][x][i] && d + adj[y][x][i] <= D) {
				nd = d + adj[y][x][i];
				pq.push({ ny,nx,nh,nd });
			}
		}
	}

	return ret;
}
inline int trans(char x) {
	if (x >= 'a') return x - 'a' + 26;
	else return x - 'A';
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 다익스트라 알고리즘 응용
결정적 깨달음		: 
시간복잡도		: O(n^2lgn)
오답 원인		: 1. 'a' - 'Z'는 1이 아닌 7...
				  2. 
*/////////////////////////////////////////////////////////////////////