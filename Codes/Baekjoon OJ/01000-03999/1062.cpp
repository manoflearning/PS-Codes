#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k;
char word[50][16];
vector<bool> exist(26, false);

vector<bool> combi(26, false);
int ans;

void combiMaker(int count, int flag);
void combiCheck();

int main() {
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%s", word[i]);

		for (int l = strlen(word[i]) - 1; l >= 0; l--)
			exist[word[i][l] - 'a'] = true;
	}
	
	int sum = 0;
	for (int i = 0; i < 26; i++)
		if (exist[i] == true) sum++;

	if (k < 5) printf("0");
	else if (sum <= k) printf("%d", n);
	else {
		combi['a' - 'a'] = true;
		combi['n' - 'a'] = true;
		combi['t' - 'a'] = true;
		combi['i' - 'a'] = true;
		combi['c' - 'a'] = true;

		exist['a' - 'a'] = false;
		exist['n' - 'a'] = false;
		exist['t' - 'a'] = false;
		exist['i' - 'a'] = false;
		exist['c' - 'a'] = false;

		combiMaker(5, 0);

		printf("%d", ans);
	}

	return 0;
}

void combiMaker(int count, int flag) {
	//base case
	if (count == k) {
		combiCheck();
		return;
	}
	//
	for (int i = flag; i < 26; i++)
		if (exist[i] == true) {
			combiMaker(count, i + 1);

			combi[i] = true;
			combiMaker(count + 1, i + 1);
			combi[i] = false;

			break;
		}
}
void combiCheck() {
	int sum = 0;

	for (int i = 0; i < n; i++) {
		bool check = true;
		for (int l = strlen(word[i]) - 1; l >= 0; l--)
			if (combi[word[i][l] - 'a'] == false) {
				check = false;
				break;
			}

		if (check) sum++;
	}

	ans = max(ans, sum);
}
/*
문제 해법		: 완전탐색
접근 방식		:
결정적 깨달음		:
오답 원인		: 1. 
				  2.
*/
//////////////////////////////////////////////////////////////////////