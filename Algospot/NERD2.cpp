#include <iostream>
#include <map>
using namespace std;

map<int, int> dots;

bool isDominated(int x, int y);
void removeDominated(int x, int y);
int registered(int x, int y);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int c;
	cin >> c;

	for (int test = 0; test < c; test++) {
		int t;
		cin >> t;

		int ans = 0;
		for (int i = 0; i < t; i++) {
			int x, y;
			cin >> x >> y;
			
			ans += registered(x, y);
		}

		cout << ans << '\n';

		dots.clear();
	}

	return 0;
}

bool isDominated(int x, int y) {
	map<int, int>::iterator it = dots.lower_bound(x);

	if (it == dots.end()) return false;
	return y < it->second;
}
void removeDominated(int x, int y) {
	map<int, int>::iterator it = dots.lower_bound(x);

	if (it == dots.begin()) return;
	
	it--;
	while (true) {
		if (it->second > y) break;
		if (it == dots.begin()) {
			dots.erase(it);
			break;
		}

		map<int, int>::iterator jt = it;
		jt--;
		dots.erase(it);
		it = jt;
	}
}
int registered(int x, int y) {
	if (isDominated(x, y)) return dots.size();
	removeDominated(x, y);
	dots[x] = y;
	return dots.size();
}
/*/////////////////////////////////////////////////////////////////////
���� �ع�		: ���� �˻� Ʈ���� ����ð��� ����, ����, Ž���� �����ϴٴ� ���� Ȱ��.
���� ���		: 
������ ������		:
���� ����		: 1.
				  2.
*//////////////////////////////////////////////////////////////////////