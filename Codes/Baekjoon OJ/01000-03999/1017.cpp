#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 50;

int N, arr[MAX + 5], A[MAX + 5], B[MAX + 5];
bool canGo[MAX + 5][MAX + 5], visited[MAX + 5];
vector<int> adj[MAX + 5], ans;

void input();
void graph_modeling();
bool isDec(int x);
int bMatch();
bool dfs(int a);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();

	graph_modeling();

	while (true) {
		int total = bMatch();
		
		if (total != N / 2) break;
		
		canGo[1][A[1]] = false;

		adj[1].clear();
		for (int i = 2; i <= N; i++)
			if (canGo[1][i]) adj[1].push_back(i);
		
		ans.push_back(arr[A[1]]);
	}

	if (ans.empty()) cout << -1 << '\n';
	else {
		sort(ans.begin(), ans.end());

		for (int x : ans) cout << x << ' ';
	}

	return 0;
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
}

void graph_modeling() {
	bool oddSt = false;
	if (arr[1] % 2 == 1) oddSt = true;

	for (int i = 1; i <= N; i++) {
		for (int l = i + 1; l <= N; l++) {
			if (isDec(arr[i] + arr[l])) {
				int odd = (arr[i] % 2 == 1 ? i : l), even = (odd == i ? l : i);
				if (oddSt) {
					canGo[odd][even] = true;
					adj[odd].push_back(even);
				}
				else {
					canGo[even][odd] = true;
					adj[even].push_back(odd);
				}
			}
		}
	}
}

bool isDec(int x) {
	for (int i = 2; i < x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

int bMatch() {
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));

	int ret = 0;
	for (int i = 1; i <= N; i++) {
		memset(visited, 0, sizeof(visited));
		if (dfs(i)) ret++;
	}
	
	return ret;
}

bool dfs(int a) {
	visited[a] = true;
	for (int b : adj[a]) {
		if (B[b] == -1 || (!visited[B[b]] && dfs(B[b]))) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}
/*//////////////////////////////////////////////////////////////////
���� �ع�		: �̺� ��Ī
������ ������		: ����Ʈ�� ������ �ߺ����� �ʴ´�. ���� ����Ʈ�� ���� �� �ִ� ��� �Ҽ��� Ȧ���̸�, ¦���� Ȧ���� ������ �̷������. ¦���� �̷���� �׷��, Ȧ���� �̷���� �׷����� ������ �� �� �ִ�.
�ð����⵵		: O(N^4)
���� ����		: 1. ������ ��ü ��??
				  2.
*///////////////////////////////////////////////////////////////////