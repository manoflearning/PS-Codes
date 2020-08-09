#include <iostream>
#include <stack>
using namespace std;

int ans;

void melody(stack<int>& str, int& fret);

int main() {
	int t, c;
	scanf("%d %d", &t, &c);

	stack<int> s1, s2, s3, s4, s5, s6;
	for (int test = 0; test < t; test++) {
		int str, fret;
		scanf("%d %d", &str, &fret);

		if (str == 1) melody(s1, fret);
		else if (str == 2) melody(s2, fret);
		else if (str == 3) melody(s3, fret);
		else if (str == 4) melody(s4, fret);
		else if (str == 5) melody(s5, fret);
		else if (str == 6) melody(s6, fret);
	}

	printf("%d", ans);

	return 0;
}

void melody(stack<int>& str, int& fret) {
	while (!str.empty() && str.top() > fret) {
		str.pop();
		ans++;
	}

	if (str.empty() || str.top() != fret) {
		str.push(fret);
		ans++;
	}
}
/*//////////////////////////////////////////////////////////////////////
���� �ع�		: ������ ������ Ȱ��
���� ���		: 
������ ������		: 
���� ����		: 1. 
				  2. 
*///////////////////////////////////////////////////////////////////////