#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	queue<int> arr;

	for (int test = 0; test < t; test++) {
		string cmd;
		cin >> cmd;

		if (cmd == "push") {
			int x;
			cin >> x;

			arr.push(x);
		}
		else if (cmd == "pop") {
			if (arr.empty()) cout << "-1\n";
			else {
				cout << arr.front() << '\n';
				arr.pop();
			}
		}
		else if (cmd == "size") cout << arr.size() << '\n';
		else if (cmd == "empty") cout << arr.empty() << '\n';
		else if (cmd == "front") {
			if (arr.empty()) cout << "-1\n";
			else cout << arr.front() << '\n';
		}
		else if (cmd == "back") {
			if (arr.empty()) cout << "-1\n";
			else cout << arr.back() << '\n';
		}
	}
}
/*//////////////////////////////////////////////////////////////////////
문제 해법		: 큐
접근 방식		:
결정적 깨달음		:
오답 원인		: 1. 
				  2. 
*///////////////////////////////////////////////////////////////////////