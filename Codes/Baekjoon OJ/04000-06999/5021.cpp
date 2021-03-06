#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;

const int MAX = 150;

int N, M, cnt = 1;
map<string, int> mp, king;
map<int, string> rev_mp;
vector<int> par[MAX + 5], child[MAX + 5];
pair<ll, int> depth[MAX + 5];

void scan();
void dfs(int now, ll dep);
string find();
bool cmp(pair<ll, int> a, pair<ll, int> b);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	for (int i = 0; i < MAX + 5; i++)
		depth[i].second = i;

	scan();

	dfs(1, ((ll)1 << 52));

	sort(depth, depth + MAX + 5, cmp);

	string ans = find();
	cout << ans << '\n';

	return 0;
}

void scan() {
	cin >> N >> M;

	string s; cin >> s;
	mp.insert({ s, cnt });
	rev_mp.insert({ cnt++, s });

	for (int i = 0; i < N; i++) {
		string ch, p1, p2;
		cin >> ch >> p1 >> p2;

		if (mp.find(ch) == mp.end()) {
			mp.insert({ ch, cnt });
			rev_mp.insert({ cnt++, ch });
		}
		if (mp.find(p1) == mp.end()) {
			mp.insert({ p1, cnt });
			rev_mp.insert({ cnt++, p1 });
		}
		if (mp.find(p2) == mp.end()) {
			mp.insert({ p2, cnt });
			rev_mp.insert({ cnt++, p2 });
		}

		map<string, int>::iterator chIt = mp.find(ch), p1It = mp.find(p1), p2It = mp.find(p2);

		child[p1It->second].push_back(chIt->second);
		child[p2It->second].push_back(chIt->second);
		par[chIt->second].push_back(p1It->second);
		par[chIt->second].push_back(p2It->second);
	}

	for (int i = 0; i < M; i++) {
		string s; cin >> s;
		king.insert({ s, 0 });
	}
}

void dfs(int now, ll dep) {
	depth[now].first += dep;
	
	for (int next : child[now]) {
		dfs(next, dep / 2);
	}
}

string find() {
	for (int i = 0; i < MAX + 5; i++) {
		map<int, string>::iterator it = rev_mp.find(depth[i].second);
		
		if (it == rev_mp.end()) continue;
		if (king.find(it->second) != king.end()) return it->second;
	}
}

bool cmp(pair<ll, int> a, pair<ll, int> b) {
	return a.first > b.first;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 
결정적 깨달음		:
시간복잡도		: 
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////