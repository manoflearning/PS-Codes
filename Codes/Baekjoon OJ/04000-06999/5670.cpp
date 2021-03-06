#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int GO_MAX = 26;

struct trie {
	int wordCnt; //이 노드를 접미사로 하지 않고, 이 노드를 포함하는 문자열의 개수
	int childCnt; //자식 노드의 개수 + 이 노드를 접미사로 하는 문자열의 개수
	trie* go[GO_MAX];

	trie() {
		wordCnt = childCnt = 0;
		fill(go, go + GO_MAX, nullptr);
	}
	~trie() {
		for (int i = 0; i < GO_MAX; i++)
			if (go[i]) delete go[i];
	}

	void insert(const string& s, int key) {
		if (s.size() == key) childCnt++;
		else {
			wordCnt++;
			int next = s[key] - 'a';
			if (!go[next]) {
				go[next] = new trie;
				childCnt++;
			}
			go[next]->insert(s, key + 1);
		}
	}

	int query() {
		int ret = (childCnt == 1) ? 0 : wordCnt;
		for (int i = 0; i < GO_MAX; i++) {
			if (go[i]) ret += go[i]->query();
		}
		return ret;
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(2);

	while (true) {
		int N; cin >> N;

		if (cin.eof()) break;

		trie* root = new trie;
		for (int i = 0; i < N; i++) {
			string s; cin >> s;
			root->insert(s, 0);
		}

		double ans = N;
		for (int i = 0; i < GO_MAX; i++) {
			if (root->go[i]) ans += root->go[i]->query();
		}
		cout << ans / N << '\n';

		delete root;
	}

	return 0;
}