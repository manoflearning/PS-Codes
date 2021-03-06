#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX 100

int dp[MAX+1];

void sort_and_comparison(int el1[], int el2[], int n);

int LIS(int arr[], int n, int flag);

int main()
{
	//input
	int n;
	std::cin>>n;
	int el1[n+1];
	int el2[n+1];
	for(int i=1; i<=n; i++)
		std::cin>>el1[i]>>el2[i];
		
	sort_and_comparison(el1, el2, n);
	
	for(int i=1; i<=n; i++)
		LIS(el2, n, i);
	
	int ans=0;
	for(int i=1; i<=n; i++)
		ans = std::max(ans, dp[i]);
	
	std::cout<<n-ans;
	
	return 0;
}

void sort_and_comparison(int el1[], int el2[], int n)
{
	int re_el1[n+1], re_el2[n+1];
	memcpy(re_el1, el1, sizeof(re_el1));
	std::sort(el1 + 1, el1 + n+1);
	
	for(int i=1; i<=n; i++)
	for(int l=1; l<=n; l++)
		if(el1[i] == re_el1[l])
		{
			re_el2[i] = el2[l];
			break;
		}
		
	memcpy(el2, re_el2, sizeof(re_el2));
}

int LIS(int arr[], int n, int flag)
{
	if(dp[flag]!=0) return dp[flag];
	
	for(int i=flag+1; i<=n; i++)
	{
		if(arr[i]>arr[flag])
			dp[flag] = std::max(dp[flag], LIS(arr, n, i));
	}
	dp[flag]++;
	
	return dp[flag];
}
