#include <iostream>

int combination(int n, int k);
//조합 구하는 함수 
int main(void) {
	int n, k;
	
	std::cin>>n>>k;
	
	std::cout<<combination(n, k);
	
	return 0;
}

int combination(int n, int k) {
	int cal=1;
	
	for(int i=n; i>n-k; i--)
		cal*=i;
	for(int i=1; i<=k; i++)
		cal/=i;
	
	return cal;
}