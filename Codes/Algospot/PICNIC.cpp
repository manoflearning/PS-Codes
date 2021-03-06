#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector< vector<int> > friends;

int friendsCounter(int flag, vector<int>& people);
bool allFriendsChecker(vector<int>& people);

int main() {
	int c;
	scanf("%d", &c);

	for (int test = 0; test < c; test++) {
		scanf("%d %d", &n, &m);

		friends.resize(m, vector<int>(2));

		for (int i = 0; i < m; i++)
			scanf("%d %d", &friends[i][0], &friends[i][1]);

		vector<int> people;
		int ans = friendsCounter(0, people);

		printf("%d\n", ans);
	}

	return 0;
}

int friendsCounter(int flag, vector<int>& people) {
	//base case
	if (flag == m || people.size() == n) {
		if (allFriendsChecker(people)) return 1;
		else return 0;
	}
	//
	int ans = 0;

	ans += friendsCounter(flag + 1, people);

	people.push_back(friends[flag][0]);
	people.push_back(friends[flag][1]);

	ans += friendsCounter(flag + 1, people);

	people.pop_back();
	people.pop_back();

	return ans;
}
bool allFriendsChecker(vector<int>& people) {
	bool check = true;

	for (int i = 0; i < n; i++) {
		bool check2 = false;
		for (int l = people.size() - 1; l >= 0; l--) {
			if (i == people[l]) {
				check2 = true;
				break;
			}
		}

		if (!check2) {
			check = false;
			break;
		}
	}

	return check;
}
/*
문제 해법		: 가능한 친구 쌍의 조합을 모두 탐색.
접근 방식		:
결정적 깨달음		:
오답 원인		: 1. 
				  2.
*/
//////////////////////////////////////////////////////////////////////
