#include <stdio.h>

void min_find(int m, int *min_set, int *min_piece);
int calculate_price(int n, int min_set, int min_piece);

int main(void) {
	int n, m;
	int min_set, min_piece;
	
	scanf("%d %d", &n, &m);
	 
	min_find(m, &min_set, &min_piece);
	
	printf("%d", calculate_price(n, min_set, min_piece));
	
	return 0;
}
//입력받는 가격 중 가장 싼 패키지 가격과 낱개 가격을 찾는 함수 
void min_find(int m, int *min_set, int *min_piece) {
	int set, piece;
	int i;
	
	scanf("%d %d", &set, &piece);
	*min_set=set, *min_piece=piece;
	for(i=1; i<m; i++) {
		scanf("%d %d", &set, &piece);
		
		if(*min_set>set) *min_set=set;
		if(*min_piece>piece) *min_piece=piece;
	}
}
//필요한 돈의 최솟값 계산 
int calculate_price(int n, int min_set, int min_piece) {
	if(min_piece*6<=min_set) return n*min_piece;
	else {
		if(n%6*min_piece < min_set) 
			return n/6*min_set + n%6*min_piece;
		else
			return (n/6+1)*min_set;
	}
}