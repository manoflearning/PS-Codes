#include <iostream>
#include <vector>
using namespace std;

const int GO_MAX = 'z' - '.' + 1;

struct trie {
	trie* go[GO_MAX];
	bool cannotErase; //�� ��带 �����ϴ� ��� ���ڿ� �� �������� �ȵǴ� ���ڿ��� �ִ°�?
	bool output;

	trie() {
		fill(go, go + GO_MAX, nullptr);
		cannotErase = output = false;
	}
	~trie() {
		for (int i = 0; i < GO_MAX; i++)
			if (go[i]) delete go[i];
	}

	void insert(const string& s, bool cannot, int key = 0) {
		if (cannot) cannotErase = true;

		if (s.size() == key) {
			if(!cannot) output = true;
		}
		else {
			int next = s[key] - '.';
			if (!go[next]) {
				if (cannot) return; //���� �������� �ȵǴ� ���ڿ��̶��, ��带 �߰����� �ʴ´�.
				go[next] = new trie;
			}
			go[next]->insert(s, cannot, key + 1);
		}
	}

	int query() {
		if (!cannotErase) return 1;

		int ret = output ? 1 : 0;
		for (int i = 0; i < GO_MAX; i++)
			if (go[i]) ret += go[i]->query();
		return ret;
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int tc; cin >> tc;

	while (tc--) {
		trie* root = new trie;

		int N1, N2;

		cin >> N1;
		for (int i = 0; i < N1; i++) {
			string s; cin >> s;
			root->insert(s, false);
		}

		cin >> N2;
		for (int i = 0; i < N2; i++) {
			string s; cin >> s;
			root->insert(s, true);
		}

		cout << root->query() << '\n';

		delete root;
	}

	return 0;
}