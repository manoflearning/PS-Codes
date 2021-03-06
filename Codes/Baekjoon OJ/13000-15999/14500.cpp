/*
문제 해법		: 재귀호출 이용한 완전탐색
접근 방식		:
결정적 깨달음	:
오답 원인		: 1. 중복 연산
				  2. 배열 범위를 벗어난 참조
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int _left = 0;
const int _right = 1;
const int _top = 2;
const int _bottom = 3;

int n, m;
vector< vector<int> > paper;

int find_criteria();

int max_calculate(int y, int x, int flag, int du_pre);
int handling(int y, int x);

int main()
{
	scanf("%d %d", &n, &m);

	paper.resize(n, vector<int>(m));

	for (int i = 0; i < n; i++)
		for (int l = 0; l < m; l++)
			std::cin >> paper[i][l];

	printf("%d", find_criteria());

	return 0;
}

int find_criteria()
{
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int l = 0; l < m; l++)
		{
			ans = max(ans, max_calculate(i, l, 1, 5));
			ans = max(ans, handling(i, l));
		}

	return ans;
}

int max_calculate(int y, int x, int flag, int du_pre)
{
	if (y < 0 || n <= y || x < 0 || m <= x) return -4001;
	if (flag == 4) return paper[y][x];

	int ans;
	if (du_pre != _left)
		ans = max_calculate(y, x - 1, flag + 1, _right);
	if (du_pre != _right)
		ans = max(ans, max_calculate(y, x + 1, flag + 1, _left));
	if (du_pre != _top)
		ans = max(ans, max_calculate(y + 1, x, flag + 1, _bottom));
	if (du_pre != _bottom)
		ans = max(ans, max_calculate(y - 1, x, flag + 1, _top));

	int r_ans = paper[y][x];
	r_ans += ans;

	return r_ans;
}
int handling(int y, int x)
{
	int ans = 0;

	if (0 <= y - 2 && x + 1 < m)
		ans = max(ans, paper[y][x] + paper[y - 1][x] + paper[y - 2][x] + paper[y - 1][x + 1]);
	if (0 <= y - 2 && 0 <= x - 1)
		ans = max(ans, paper[y][x] + paper[y - 1][x] + paper[y - 2][x] + paper[y - 1][x - 1]);
	if (y + 2 < n && x + 1 < m)
		ans = max(ans, paper[y][x] + paper[y + 1][x] + paper[y + 2][x] + paper[y + 1][x + 1]);
	if (y + 2 < n && 0 <= x - 1)
		ans = max(ans, paper[y][x] + paper[y + 1][x] + paper[y + 2][x] + paper[y + 1][x - 1]);
	if (0 <= x - 2 && 0 <= y - 1)
		ans = max(ans, paper[y][x] + paper[y][x - 1] + paper[y][x - 2] + paper[y - 1][x - 1]);
	if (0 <= x - 2 && y + 1 < n)
		ans = max(ans, paper[y][x] + paper[y][x - 1] + paper[y][x - 2] + paper[y + 1][x - 1]);
	if (x + 2 < m && 0 <= y - 1)
		ans = max(ans, paper[y][x] + paper[y][x + 1] + paper[y][x + 2] + paper[y - 1][x + 1]);
	if (x + 2 < m && y + 1 < n)
		ans = max(ans, paper[y][x] + paper[y][x + 1] + paper[y][x + 2] + paper[y + 1][x + 1]);

	return ans;
}