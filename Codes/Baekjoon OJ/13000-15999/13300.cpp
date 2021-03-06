#include <stdio.h>

int how_many_room(int n, int k);

int main(void) {
	int n, k;
	
	scanf("%d %d", &n, &k);
	
	printf("%d", how_many_room(n, k));
	
	return 0;
}

int how_many_room(int n, int k) {
	int school[2][6]={0};
	int s, y;
	int count=0;
	int i, l;
	
	for(i=0; i<n; i++) {
		scanf("%d %d", &s, &y);
		
		school[s][y-1]++;
	}
	
	for(i=0; i<2; i++)
		for(l=0; l<6; l++) {
			if(school[i][l]%k==0)
				count+=school[i][l]/k;
			else
				count+=school[i][l]/k+1;
		}
		
		
	return count;
}