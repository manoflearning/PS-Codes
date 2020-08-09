#include <iostream>
#include <vector>
using namespace std;

const int MAX = 50000;

vector<int> tree[MAX + 1];
int parentNode[MAX + 1];
int depth[MAX + 1];

void calDepth(int node, int visited, int count);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int node1, node2;
		cin >> node1 >> node2;

		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}

	calDepth(1, 0, 1);

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int node1, node2;
		cin >> node1 >> node2;

		while (depth[node1] != depth[node2]) {
			if (depth[node1] > depth[node2]) node1 = parentNode[node1];
			else node2 = parentNode[node2];
		}

		while (node1 != node2) {
			node1 = parentNode[node1];
			node2 = parentNode[node2];
		}

		cout << node1 << '\n';
	}

	return 0;
}

void calDepth(int node, int visited, int count) {
	depth[node] = count;

	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i] == visited) continue;

		parentNode[tree[node][i]] = node;
		calDepth(tree[node][i], node, count + 1);
	}
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: Lowest Common Ancester
���� ���		: ���� ������ ã�� �� ������ ���̸� ��ġ�ϰ� �����. �� �ܰ踦 �� �� �÷�����.
������ ������		: Ʈ���� ��Ʈ ��带 �ȴٴ� ���� �Ͽ�, Ʈ���� ���̿� �θ�-�ڽ� ���踦 ��Ȯ�� �ϴ� ������ O(n)�� �ð��� �ɸ�.
���� ����		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////