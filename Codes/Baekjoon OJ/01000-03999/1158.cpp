#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
vector<int> arr;

int main() {
	scanf("%d %d", &n, &k);

	arr.resize(n);
	for (int i = 0; i < n; i++)
		arr[i] = i + 1;

	printf("<%d", arr[k - 1]);
	arr.erase(arr.begin() + k - 1);
	while (arr.size() != 0) {
		static int flag = k - 2;
		static int count = 0;

		flag++;
		count++;

		if (flag == arr.size()) flag = 0;
		if (count % k == 0) {
			printf(", %d", arr[flag]);
			arr.erase(arr.begin() + flag);
			flag--;
		}
	}
	printf(">");

	return 0;
}
/*
문제 해법		: 
접근 방식		: 
결정적 깨달음	: 
오답 원인		: 1. 
				  2. 
*/
//////////////////////////////////////////////////////////////////////