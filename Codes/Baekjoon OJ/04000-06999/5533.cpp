#include <iostream>
#include <vector>
using namespace std;

const int MAX = 200;

int player[MAX + 5][4], cnt[4][101]; 
//int[a][b]은 a번째 게임에 b가 적힌 카드의 등장 횟수

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		for (int l = 1; l <= 3; l++) {
			cin >> player[i][l];
			cnt[l][player[i][l]]++;
		}
	}

	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int l = 1; l <= 3; l++) {
			if (cnt[l][player[i][l]] == 1) sum += player[i][l];
		}

		cout << sum << '\n';
	}

	return 0;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 
결정적 깨달음		: 
시간복잡도		: 
오답 원인		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////