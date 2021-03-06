#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct shark {
	int r, c, s, d, z;
};

int R, C, M;
shark shk[10005];
bool isCatched[10005];
int shkNum[105][105];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> R >> C >> M;

	memset(shkNum, -1, sizeof(shkNum));

	for (int i = 0; i < M; i++) {
		shark& s = shk[i];
		cin >> s.r >> s.c >> s.s >> s.d >> s.z;
		shkNum[s.r][s.c] = i;
	}

	int ans = 0;
	for (int x = 1; x <= C; x++) {
		/*for (int y = 1; y <= R; y++) {
			for (int x = 1; x <= C; x++) {
				if (shkNum[y][x] == -1) cout << 0 << ' ';
				else cout << shk[shkNum[y][x]].z << ' ';
			}
			cout << '\n';
		}
		cout << '\n';*/

		for (int y = 1; y <= R; y++) {
			if (shkNum[y][x] == -1) continue;

			int num = shkNum[y][x];

			isCatched[num] = true;
			ans += shk[num].z;
			break;
		}

		memset(shkNum, -1, sizeof(shkNum));

		for (int i = 0; i < M; i++) {
			if (isCatched[i]) continue;
			
			shark& s = shk[i];
			int mv = s.s;

			if (s.d == 1 || s.d == 2) {
				if (mv >= 2 * (R - 1)) mv %= 2 * (R - 1);
			}
			else if (s.d == 3 || s.d == 4) {
				if (mv >= 2 * (C - 1)) mv %= 2 * (C - 1);
			}

			while (true) {
				int left = 0;
				if (s.d == 1) left = s.r - 1;
				else if (s.d == 2) left = R - s.r;
				else if (s.d == 3) left = C - s.c;
				else if (s.d == 4) left = s.c - 1;
				
				if (mv <= left) {
					if (s.d == 1) s.r -= mv;
					else if (s.d == 2) s.r += mv;
					else if (s.d == 3) s.c += mv;
					else if (s.d == 4) s.c -= mv;
					break;
				}

				mv -= left;
				if (s.d == 1) s.r = 1;
				else if (s.d == 2) s.r = R;
				else if (s.d == 3) s.c = C;
				else if (s.d == 4) s.c = 1;
				
				if (s.d & 1) s.d++;
				else s.d--;
			}

			if (shkNum[s.r][s.c] == -1) shkNum[s.r][s.c] = i;
			else {
				int prv = shkNum[s.r][s.c], now = i;

				if (shk[prv].z > shk[now].z) {
					isCatched[now] = true;
				}
				else {
					isCatched[prv] = true;
					shkNum[s.r][s.c] = now;
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}