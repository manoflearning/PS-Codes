#include <iostream>

#define MAX 100000

int dp[MAX+1];

int main()
{
	int n;
	std::cin>>n;
	
	int arr[n+1];
	for(int i=1; i<=n; i++)
		std::cin>>arr[i];
	
	dp[1] = arr[1];
	int max = dp[1];
	for(int i=2; i<=n; i++)
	{
		dp[i] = std::max(dp[i-1], 0);
		dp[i] += arr[i];
		max = std::max(max, dp[i]);
	}
	/*for(int i=1; i<=n; i++)
	{
		int sam=0;
		for(int l=i; l>=1; l--)
		{
			sam += arr[l];
		
			max = std::max(max, sam);
		}
	}*/
	
	std::cout<<max;
	
	return 0;
}
