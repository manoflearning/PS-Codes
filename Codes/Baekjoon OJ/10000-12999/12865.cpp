#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX 100000

#define WEIGHT 0
#define VALUE 1

int dp[MAX+1][101];

int max_value(int n, int k, int thing[][2], int flag);

int main() {
	for(int i=0; i<=MAX; i++)
	for(int l=0; l<=100; l++)
		dp[i][l] = -1;
	//input
	int n, k;
	std::cin>>n>>k;
	int thing[n+1][2];
	for(int i=1; i<=n; i++)
		std::cin>>thing[i][WEIGHT]>>thing[i][VALUE];
		
	std::cout<<max_value(n, k, thing, 0)<<'\n';
	
	return 0;
}

int max_value(int n, int k, int thing[][2], int flag)
{
	if(dp[k][flag]!=-1) return dp[k][flag];
	if(k==0) return 0;
	
	for(int i=flag+1; i<=n; i++)
	{
		if(k-thing[i][WEIGHT] >= 0)
		{	
			dp[k][flag] = std::max(dp[k][flag], thing[i][VALUE] + max_value(n, k-thing[i][WEIGHT], thing, i));
		}
	}
	
	if(dp[k][flag] == -1)
		dp[k][flag] = 0;

	return dp[k][flag];
}