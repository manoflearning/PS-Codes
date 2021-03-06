#include <stdio.h>

void dayoftheweek_check(int x, int y) {
	int check;
	
	
	while(1) {
		if(x==1) break;
		
		if(x-1==1 || x-1==3 || x-1==5 || x-1== 7 || x-1==8 || x-1==10 || x-1==12) y+=31;
		else if(x-1==4 || x-1==6 || x-1==9 || x-1==11) y+=30;
		else if(x-1==2) y+=28;
		
		x--;
	}
	
	check = y%7;
	
	if(check==0) printf("SUN");
	else if(check==1) printf("MON");
	else if(check==2) printf("TUE");
	else if(check==3) printf("WED");
	else if(check==4) printf("THU");
	else if(check==5) printf("FRI");
	else if(check==6) printf("SAT");
}

int main (void) {
	int x, y;
	
	scanf("%d %d", &x, &y);
	
	dayoftheweek_check(x, y);
	
	return 0;
}
