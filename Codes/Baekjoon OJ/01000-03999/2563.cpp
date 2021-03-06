#include <iostream>
using namespace std;

bool visited[105][105];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;

	int ans = 0;
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;

		for (int y = b; y < b + 10; y++) {
			for (int x = a; x < a + 10; x++) {
				if (visited[y][x]) continue;
				else {
					visited[y][x] = true;
					ans++;
				}
			}
		}
	}

	cout << ans;

	return 0;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 구현
결정적 깨달음		: 
시간복잡도		: O(n)
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////