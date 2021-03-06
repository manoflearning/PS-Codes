#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int movePen[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

char boggle[5][5];
char word[11];
int wordLen;

vector< vector< vector<int> > > dp;

bool findWord(int y, int x, int flag);

int main() {
	int c;
	scanf("%d", &c);

	for (int test = 0; test < c; test++) {
		for (int y = 0; y < 5; y++)
			for (int x = 0; x < 5; x++) {
				scanf(" %c", &boggle[y][x]);
			}

		int c_word;
		scanf("%d", &c_word);

		for (int t = 0; t < c_word; t++) {
			scanf("%s", word);

			wordLen = strlen(word);

			dp.resize(5, vector< vector<int> >(5, vector<int>(wordLen, -1)));

			bool check = false;
			for (int y = 0; y < 5; y++)
				for (int x = 0; x < 5; x++) {
					if (findWord(y, x, 0)) {
						check = true;
						break;
					}
				}
			
			printf("%s ", word);
			if (check) printf("YES\n");
			else printf("NO\n");

			dp.clear();
		}
	}

	return 0;
}

bool findWord(int y, int x, int flag) {
	//memoization
	if (dp[y][x][flag] != -1) return dp[y][x][flag];
	//base case
	if (flag == wordLen - 1) {
		if (boggle[y][x] == word[flag]) return true;
		else return false;
	}
	//
	dp[y][x][flag] = false;

	if (boggle[y][x] != word[flag]) return dp[y][x][flag];

	for (int i = 0; i < 8; i++) {
		int y_move = y + movePen[i][0];
		int x_move = x + movePen[i][1];

		if (y_move != -1 && y_move != 5 && x_move != -1 && x_move != 5) {
			if (findWord(y_move, x_move, flag + 1)) dp[y][x][flag] = true;
		}
	}

	return dp[y][x][flag];
}
/*
문제 해법		: 동적 계획법
접근 방식		:
결정적 깨달음		:
오답 원인		: 1. 
				  2.
*/
//////////////////////////////////////////////////////////////////////
