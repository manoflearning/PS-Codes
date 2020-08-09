#include <stdio.h>
#include <math.h>
int i;

int main (void) {
	long a, b, c, abc;
	int arr[10]={0,};
	
	scanf("%d %d %d", &a, &b, &c);
	abc = a*b*c;
	
	/*for(i=1; ; i++) {
		arr[abc%10]++;
		abc=abc/10;
		
		if(abc==0) break;
	}성공한 알고리즘*/ 
	
	for(i=1; pow(10, i)/10*10<=abc*10; i++)
		arr[abc/(int)pow(10, i-1)%10]++;
	//오류의 가능성이 있어 보이는 알고리즘*/
	
	for(i=0; i<10; i++)
		printf("%d\n", arr[i]);
	
	return 0;
}
