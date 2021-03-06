#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 200;

const int dy[4] = { 1, 0, -1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

struct vyx {
	int v, y, x;
	vyx(int pv, int py, int px) : v(pv), y(py), x(px) {}
};

int N, K, S, enY, enX;
int arr[MAX + 5][MAX + 5];
vector<vyx> virus;

void scan();
void bfs();
bool cmp(vyx a, vyx b);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//입력
	scan();

	//증식
	sort(virus.begin(), virus.end(), cmp);
	
	bfs();

	//출력
	cout << arr[enY][enX] << endl;

	return 0;
}

void scan() {
	cin >> N >> K;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> arr[y][x];
			if (arr[y][x] != 0)
				virus.push_back(vyx(arr[y][x], y, x));
		}
	}

	cin >> S >> enY >> enX;
}

void bfs() {
	queue<vyx> q;
	for (auto i : virus) q.push(i);
	
	for (int i = 0; i < S; i++) {
		int siz = q.size();
		for (int l = 0; l < siz; l++) {
			int v = q.front().v, y = q.front().y, x = q.front().x;
			q.pop();

			for (int j = 0; j < 4; j++) {
				int ny = y + dy[j], nx = x + dx[j];
				if (ny < 1 || N < ny || nx < 1 || N < nx) continue;
				if (arr[ny][nx] == 0) {
					arr[ny][nx] = v;
					q.push(vyx(v, ny, nx));
				}
			}
		}
	}
}

bool cmp(vyx a, vyx b) {
	return a.v < b.v;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 구현
결정적 깨달음		: 
시간복잡도		: O(N^2lgN)
오답 원인		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////