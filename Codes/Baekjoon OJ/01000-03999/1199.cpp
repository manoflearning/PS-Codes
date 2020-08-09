#include <iostream>
#include <vector>
using namespace std;

const int MAXV = 1e3;

int N, adj[MAXV + 5][MAXV + 5], degree[MAXV + 5], E;
vector<int> euler_circult;

void DFS(int now);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int u = 1; u <= N; u++) {
		for (int v = 1; v <= N; v++) {
			cin >> adj[u][v];
			degree[u] += adj[u][v];
			degree[v] += adj[u][v];
			E += adj[u][v];
		}
	}

	E /= 2;

	//���Ϸ� ȸ�� ���� ���� �Ǻ�
	//��� ������ ������ ¦�� �� Ȥ�� 0���̰�, ��� ������ �ϳ��� ������Ʈ�� ���ԵǸ� ���Ϸ� ȸ�δ� �����Ѵ�.
	//�׷��� ������� ���Ϸ� ȸ�δ� �������� �ʴ´�.
	for (int v = 1; v <= N; v++) {
		degree[v] /= 2;
		if (degree[v] % 2 != 0) {
			cout << -1;
			return 0;
		}
	}

	//dfs�� ���Ϸ� ȸ�� ���ϱ�
	DFS(1);
	
	//��� ������ ���� ������Ʈ�� �ִ°�?
	if (euler_circult.size() != E + 1) cout << -1;
	else {
		for (int v : euler_circult)
			cout << v << ' ';
	}

	return 0;
}

void DFS(int now) {
	//�������
	for(int next = 1; next <= N; next++)
		if (adj[now][next]) {
			adj[now][next]--;
			adj[next][now]--;
			DFS(next);
		}
	//����� �������� �迭�� �����ȴ�.
	euler_circult.push_back(now);
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: ���Ϸ� ȸ��
������ ������		: 
�ð����⵵		: O(|V||E|)
���� ����		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////