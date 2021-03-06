#include <iostream>
#include <deque>
using namespace std;

int main() {
	deque<char> front, back;

	string a, t;
	cin >> a >> t;

	int front_index = 0, last_index = t.size() - 1;

	while (front_index <= last_index) {
		while (front_index <= last_index) {
			bool b = false;
			front.push_back(t[front_index]);
			front_index++;
			if (front.size() >= a.size()) {
				b = true;
				for (int i = 0; i < a.size(); i++) {
					if (a[i] != front[front.size() - a.size() + i]) {
						b = false;
						break;
					}
				}
			}
			if (b) {
				for (int i = 0; i < a.size(); i++) front.pop_back();
				break;
			}
		}
		while (front_index <= last_index) {
			back.push_front(t[last_index]);
			last_index--;
			bool b = false;
			if (back.size() >= a.size()) {
				b = true;
				for (int i = 0; i < a.size(); i++) {
					if (a[i] != back[i]) {
						b = false;
						break;
					}
				}
			}
			if (b) {
				for (int i = 0; i < a.size(); i++)
					back.pop_front();
				break;
			}
		}
	}

	string ans;
	for (int i = 0; i < front.size(); i++) ans.push_back(front[i]);
	for (int i = 0; i < back.size(); i++) ans.push_back(back[i]);
	while (ans.find(a) != string::npos)
		ans.erase(ans.find(a), a.size());
	
	if (!ans.empty()) cout << ans;

	return 0;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////