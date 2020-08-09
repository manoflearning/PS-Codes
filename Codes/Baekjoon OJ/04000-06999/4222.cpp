#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <map>
#include <algorithm>
#define ll long long
#define pii pair<int, int>
using namespace std;

const int MAXV = 5 * 1e4;

int dfsn[MAXV + 5], dCnt, aPCnt[MAXV + 5];
vector<int> adj[MAXV + 5], vInBcc[MAXV + 5];
vector<map<int, int>> bcc;
stack<pii> stk;

void reset();
int dfs(int now, int prv = -1);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int test = 1; ; test++) {
		reset();

		int N = 0, M; 
		cin >> M;

		if (M == 0) break;

		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
			N = max({ N, a, b });
		}

		//dfs Ʈ��
		dfs(N); 

		//����ó��: �׷����� �ϳ��� bcc�� �̷���� ���� ���
		if (bcc.size() == 1) {
			int combi = bcc[0].size() * (bcc[0].size() - 1) / 2;
			cout << "Case " << test << ": 2 " << combi << '\n';
			continue;
		}

		//bcc���� ������ ã��: �� �̻��� bcc���� �����ϴ� ������ ������
		for (int i = 0; i < bcc.size(); i++) {
			for (pii v : bcc[i]) {
				vInBcc[v.first].push_back(i);
			}
		}

		//�� bcc�� ������ ���� ����
		for (int v = 1; v <= N; v++) {
			if (vInBcc[v].size() >= 2) {
				for (int i : vInBcc[v]) aPCnt[i]++;
			}
		}
		
		//
		int cnt = 0;
		ll combi = 1;

		for (int i = 0; i < bcc.size(); i++) {
			if (aPCnt[i] == 1) {
				cnt++;
				combi *= bcc[i].size() - 1;
			}
		}
		
		cout << "Case " << test << ": " << cnt << " " << combi << '\n';
	}

	return 0;
}

void reset() {
	memset(dfsn, -1, sizeof(dfsn));
	dCnt = 0;
	memset(aPCnt, 0, sizeof(aPCnt));
	for (int i = 0; i < MAXV + 5; i++) {
		adj[i].clear(); vInBcc[i].clear();
	}
	bcc.clear();
}

int dfs(int now, int prv) {
	int ret = dfsn[now] = ++dCnt;
	
	for (int next : adj[now]) {
		if (next == prv) continue;

		if (dfsn[now] > dfsn[next]) stk.push(pii(now, next));

		if (dfsn[next] != -1) ret = min(ret, dfsn[next]);
		else {
			int tmp = dfs(next, now);
			ret = min(ret, tmp);

			if (tmp >= dfsn[now]) {
				map<int, int> mp;
				while (true) {
					pii t = stk.top();
					stk.pop();

					mp.insert({ t.first, t.first });
					mp.insert({ t.second, t.second });

					if (t == pii(now, next)) break;
				}

				bcc.push_back(mp);
			}
		}
	}

	return ret;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: ������
������ ������		: bcc�� �������� �ϰ�, �������� �������� �ϸ� Ʈ�� ������ �����Ѵ�.
�ð����⵵		: O(|V|lg|V| + |E|lg|E|)
���� ����		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////