#include <iostream>

void calculate(int n, int radius[]);

int main(void) {
	int n;
	int radius[100];
	
	std::cin>>n;
	
	for(int i=0; i<n; i++)
		std::cin>>radius[i];
	
	calculate(n, radius);
	
	return 0;
}

void calculate(int n, int radius[]) {
	for(int i=1; i<n; i++) {
		int f;
		//기약분수 찾기
		if(radius[i]>=radius[0]) f = radius[0];
		else f = radius[i];
		
		while(1) {
			if(radius[0]%f==0 && radius[i]%f==0) break;
				
			f--;
			
			if(f<=1) break;
		}
		
		if(f>1)
			std::cout<<radius[0]/f<<'/'<<radius[i]/f<<std::endl;
		else
			std::cout<<radius[0]<<'/'<<radius[i]<<std::endl;
	}
}
