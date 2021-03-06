#include <stdio.h>

struct dunkchi {
	int w; //weight
	int h; //height
	int r; //rank
};

void dunkchi_rank(struct dunkchi dc[], int N) {
	int i, l;
	int count;
	
	for(i=0; i<N; i++) {
		count=0;
		for(l=0; l<N; l++) {
			if(i==l) continue;
			
			if(dc[i].w<dc[l].w && dc[i].h<dc[l].h) count++;
			//else if(dc[i].w>dc[l].w || dc[i].h>dc[l].h) count+=1;
		}
		
		dc[i].r=count+1;
	}
}

int main (void) {
	struct dunkchi dc[50];
	int N;
	int i;
	
	scanf("%d", &N);
	
	for(i=0; i<N; i++)
		scanf("%d %d", &dc[i].w, &dc[i].h);
		
	dunkchi_rank(dc, N);
	
	for(i=0; i<N; i++)
		printf("%d ", dc[i].r);
	
	return 0;
}