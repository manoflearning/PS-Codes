#include <iostream>
#include <algorithm>

#define MAX 1000

int dp[MAX+1];

struct counseling_schedule_and_money
{
	int date;
	int money;
};

int count_max_gain(struct counseling_schedule_and_money cs[], int n, int flag);

int main()
{
	int n;
	std::cin>>n;
	struct counseling_schedule_and_money cs[n+1];
	for(int i=1; i<=n; i++)
		std::cin>>cs[i].date>>cs[i].money;
	
	int max = 0;
	for(int i=1; i<=n; i++)
		max = std::max(max, count_max_gain(cs, n, i));
	
	/*int max = dp[1];
	for(int i=2; i<=n; i++)
		//std::cout<<dp[i]<<'\n';
		max = std::max(max, dp[i]);*/
	
	std::cout<<max;
	
	return 0;
}

int count_max_gain(struct counseling_schedule_and_money cs[], int n, int flag)
{
	if(dp[flag]!=0) return dp[flag];
	
	for(int i=flag+cs[flag].date; i<=n; i++)
		dp[flag] = std::max(dp[flag], count_max_gain(cs, n, i));
		
	if(flag+cs[flag].date - 1 <= n)
		dp[flag] += cs[flag].money;
	
	return dp[flag];
}