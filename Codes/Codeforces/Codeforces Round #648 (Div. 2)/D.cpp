#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vvc vector<vector<char>>

const int INF = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

int R, C;
vs arr;
bool visited[55][55];

int dfs(int y, int x);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;

	while (tc--) {
		cin >> R >> C;

		arr.resize(R);

		int cntG = 0, cntB = 0;
		for (int y = 0; y < R; y++) {
			cin >> arr[y];
			for (int x = 0; x < C; x++) {
				if (arr[y][x] == 'G') cntG++;
				else if (arr[y][x] == 'B') cntB++;

				visited[y][x] = false;
			}
		}
		
		if (cntG == 0) cout << "Yes\n";
		else if (cntG > 0) {
			if (cntB == 0) {
				int canGo = dfs(R - 1, C - 1);
				if (canGo == cntG) cout << "Yes\n";
				else cout << "No\n";
			}
			else if (cntB > 0) {
				bool Yes = true;
				for (int y = 0; y < R; y++) {
					for (int x = 0; x < C; x++) {
						if (arr[y][x] != 'B') continue;
						for (int i = 0; i < 4; i++) {
							int ny = y + dy[i], nx = x + dx[i];
							if (ny < 0 || R <= ny || nx < 0 || C <= nx) continue;

							if (arr[ny][nx] == 'G') Yes = false;
							if (arr[ny][nx] == '.') arr[ny][nx] = '#';
						}
					}
				}

				if (arr[R - 1][C - 1] == '#' || !Yes) cout << "No\n";
				else {
					int canGo = dfs(R - 1, C - 1);
					if (canGo == cntG) cout << "Yes\n";
					else cout << "No\n";
				}
			}
		}
	}

	return 0;
}

int dfs(int y, int x) {
	visited[y][x] = true;

	int ret = 0;
	if (arr[y][x] == 'G') ret++;
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || R <= ny || nx < 0 || C <= nx) continue;
		if (visited[ny][nx]) continue;
		if (arr[ny][nx] == '#') continue;
		ret += dfs(ny, nx);
	}
	return ret;
}

/*int tc; cin >> tc;

	while (tc--) {
		int N; cin >> N;

		vector<pii> A(N);
		for (auto& i : A) cin >> i.first;
		for (auto& i : A) cin >> i.second;

		vector<pii> sorted = A;

		sort(sorted.begin(), sorted.end());

		bool Yes = true;
		for (int i = 0; i < N; i++) {
			for (int l = i + 1; l < N; l++) {

			}
		}

		if (Yes) cout << "Yes\n";
		else cout << "No\n";
	}*/