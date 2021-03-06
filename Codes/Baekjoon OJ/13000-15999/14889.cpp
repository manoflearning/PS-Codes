/*
문제 해법		: 완전 탐색
접근 방식		: 
결정적 깨달음	: 
오답 원인		: 1. 
				  2.
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
vector< vector<int> > cv;

vector<int> Com;
vector< vector<int> > ComStor;
int comCount;

void findCom(int flag = 0);

int calMin();

int main() {
	scanf("%d", &n);

	cv.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int l = 0; l < n; l++) {
			cin >> cv[i][l];
		}

	findCom();

	printf("%d", calMin());

	return 0;
}

void findCom(int flag) {
	if (Com.size() == n / 2) {
		ComStor.push_back(Com);
		comCount++;
		return;
	}

	for (int i = flag; i < n; i++) {
		Com.push_back(i);
		findCom(i + 1);
		Com.pop_back();
	}
}

int calMin() {
	int ans = INT_MAX;
	
	for (int i = 0; i < comCount / 2; i++) {
		int cSum1 = 0;
		int cSum2 = 0;
		for (int l = 0; l < n / 2; l++)
			for (int j = l + 1; j < n / 2; j++) {
				cSum1 += cv[ComStor[i][l]][ComStor[i][j]] + cv[ComStor[i][j]][ComStor[i][l]];

				cSum2 += cv[ComStor[comCount - i - 1][l]][ComStor[comCount - i - 1][j]] + cv[ComStor[comCount - i - 1][j]][ComStor[comCount - i - 1][l]];
			}

		ans = min(ans, abs(cSum1 - cSum2));
	}

	return ans;
}