#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> card;

bool bsearch(int left, int right, int ans);

int main() {
	//input
	scanf("%d", &n);
	card.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &card[i]);
	scanf("%d", &m);
	//
	sort(card.begin(), card.end());
	//
	for (int test = 0; test < m; test++) {
		int ans;
		scanf("%d", &ans);

		if (bsearch(0, n - 1, ans))
			printf("1 ");
		else
			printf("0 ");
	}

	return 0;
}

bool bsearch(int left, int right, int ans) {
	//base case
	if (left > right) return false;
	//
	int flag = (left + right) / 2;

	if (card[flag] > ans) return bsearch(left, flag - 1, ans);
	if (card[flag] < ans) return bsearch(flag + 1, right, ans);
	if (card[flag] == ans) return true;
}

/*
문제 해법		: 이분 탐색
접근 방식		:
결정적 깨달음	:
오답 원인		: 1. 
				  2.
*/