/*
문제 해법		: 
접근 방식		: 
결정적 깨달음	: 
오답 원인		: 기저조건의 탐색이 함수에서 가장 먼저 와야함. 
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > dp;

int n, m;
vector< vector<int> > lab;

int walls_in_empty();

int find_virus();

int find_safe_area(int y, int x);

int main()
{
	std::cin>>n>>m;
	
	dp.resize(n, vector<int>(m, 0));
	lab.resize(n, vector<int>(m));
	
	int one_count = 0;
	for(int i=0; i<n; i++)
	for(int l=0; l<m; l++)
	{
		cin>>lab[i][l];
		if(lab[i][l] == 1)
			one_count++;
	}
	
	printf("%d", walls_in_empty() - (one_count+3));
	
	return 0;
}

int walls_in_empty()
{
	int ans = 65;
	
	for(int i=0; i<n*m; i++)
	for(int l=i+1; l<n*m; l++)
	for(int j=l+1; j<n*m; j++)
	{
		if(lab[i/m][i%m]==0 && lab[l/m][l%m]==0 && lab[j/m][j%m]==0)
		{
			lab[i/m][i%m] = 1;
			lab[l/m][l%m] = 1;
			lab[j/m][j%m] = 1;
			
			ans = min(ans, find_virus());
			
			dp.clear();
			dp.resize(n, vector<int>(m, 0));
			
			lab[i/m][i%m] = 0;
			lab[l/m][l%m] = 0;
			lab[j/m][j%m] = 0;
		}
	}
	
	return n*m - ans;
}

int find_virus()
{
	int sum = 0;
	
	for(int i=0; i<n; i++)
	for(int l=0; l<m; l++)
	{
		if(lab[i][l] == 2)
			sum += find_safe_area(i, l);
	}
	
	return sum;
}

int find_safe_area(int y, int x)
{
	if(y<0 || n<=y || x<0 || m<=x) return 0;
	if(lab[y][x] == 1) return 0;
	if(dp[y][x] == 1) return 0;
	
	dp[y][x] = 1;
	
	int s_count = 0;
	s_count += find_safe_area(y+1, x);
	s_count += find_safe_area(y-1, x);
	s_count += find_safe_area(y, x+1);
	s_count += find_safe_area(y, x-1);
	
	int count = s_count;
	count++;
	
	return count;
}