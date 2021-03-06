#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXV = 100;

int N;
map<string, int> mp;
map<int, string> rev_mp;
vector<int> adj[MAXV + 5];

//scc 찾기
int label[MAXV + 5], lCnt, sNum[MAXV + 5], sCnt;
stack<int> stk;
vector<vector<int>> SCC;
bool finished[MAXV + 5];

//scc 그래프
vector<int> sAdj[MAXV + 5], rev_sAdj[MAXV + 5];
int indeg[MAXV + 5], rev_indeg[MAXV + 5];
bool isSubDic[MAXV + 5];

//입력, 해싱, 그래프 구현
void scan();
void divide_line(string& line, vector<string>& s);
void multi_check(map<string, int>::iterator& it, string& s, int& cnt);

//scc 찾기
int DFS(int v);

//scc 그래프 처리
void rev_topo_sort();

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		lCnt = sCnt = 0;
		SCC.clear(), mp.clear(), rev_mp.clear();
		memset(sNum, 0, sizeof(sNum));
		memset(label, -1, sizeof(label));
		memset(finished, 0, sizeof(finished));
		memset(indeg, 0, sizeof(indeg));
		memset(rev_indeg, 0, sizeof(rev_indeg));
		memset(isSubDic, 0, sizeof(isSubDic));
		for (int i = 0; i < MAXV + 5; i++) {
			adj[i].clear(); sAdj[i].clear(); rev_sAdj[i].clear();
		}

		//테스트케이스 시작
		cin >> N;
		if (N == 0) break;

		//입력, 해싱
		scan();

		//dfs 스패닝 트리
		for (int v = 1; v <= N; v++)
			if (label[v] == -1) DFS(v);

		//scc 그래프 구현
		for (int v = 1; v <= N; v++) {
			int sV = sNum[v];
			for (int next : adj[v]) {
				int sNext = sNum[next];
				if (sV == sNext) continue;
				sAdj[sV].push_back(sNext);
				rev_sAdj[sNext].push_back(sV);
				indeg[sNext]++;
				rev_indeg[sV]++;
			}
		}
		
		//최소 sub-dictionary 찾기
		vector<string> ans;
		
		for (int sV = 0; sV < sCnt; sV++) {
			if (indeg[sV] == 0) isSubDic[sV] = true;
		}

		rev_topo_sort();

		for (int sV = 0; sV < sCnt; sV++) {
			if (isSubDic[sV]) {
				map<int, string>::iterator it;
				for (int i = 0; i < SCC[sV].size(); i++) {
					it = rev_mp.find(SCC[sV][i]);
					ans.push_back(it->second);
				}
			}
		}
		
		//출력
		sort(ans.begin(), ans.end());

		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << ' ';
		cout << '\n';
	}

	return 0;
}

void scan() {
	int cnt = 1;

	cin.ignore();
	for (int i = 0; i < N; i++) {
		//줄 단위로 입력 받음
		string line; getline(cin, line);
		
		//단어 단위로 나누어 저장
		vector<string> s;
		divide_line(line, s);

		//해싱, 그래프 구현
		map<string, int>::iterator v = mp.find(s[0]);
		multi_check(v, s[0], cnt);

		for (int i = 1; i < s.size(); i++) {
			map<string, int>::iterator u = mp.find(s[i]);
			multi_check(u, s[i], cnt);
			adj[u->second].push_back(v->second);
		}
	}
}

void divide_line(string& line, vector<string>& s) {
	int L = 0, R;
	for (R = 1; R < line.size(); R++) {
		if (line[R] == ' ') {
			s.push_back(line.substr(L, R - L));
			L = R + 1;
		}
	}
	s.push_back(line.substr(L, R));
}

void multi_check(map<string, int>::iterator& it, string& s, int& cnt) {
	if (it == mp.end()) {
		mp.insert({ s, cnt });
		rev_mp.insert({ cnt++, s });
		it = mp.find(s);
	}
}

int DFS(int v) {
	label[v] = lCnt++;
	stk.push(v);

	int ret = label[v];
	for (int next : adj[v]) {
		if (label[next] == -1) ret = min(ret, DFS(next));
		else if (!finished[next]) ret = min(ret, label[next]);
	}

	if (ret == label[v]) {
		vector<int> vSCC;
		while (true) {
			int t = stk.top();
			stk.pop();

			vSCC.push_back(t);
			sNum[t] = sCnt;
			finished[t] = true;

			if (t == v) break;
		}

		SCC.push_back(vSCC);
		sCnt++;
	}

	return ret;
}

void rev_topo_sort() {
	queue<int> q;
	
	for (int sV = 0; sV < sCnt; sV++)
		if (rev_indeg[sV] == 0) q.push(sV);

	while (!q.empty()) {
		int n = q.front();
		q.pop();

		if (SCC[n].size() > 1) isSubDic[n] = true;

		for (int next : rev_sAdj[n]) {
			if (isSubDic[n]) isSubDic[next] = true;
			if (--rev_indeg[next] == 0) q.push(next);
		}
	}
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: SCC + 위상 정렬
결정적 깨달음		: 
시간복잡도		: O(|V|lg|V| + |E|)
오답 원인		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////