#include <iostream>
using namespace std;

struct xy {
	int x; int y;
};

xy p1, p2, p3;

int cross(xy a, xy b);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

	cout << cross({ p2.x - p1.x, p2.y - p1.y }, { p3.x - p2.x, p3.y - p2.y });

	return 0;
}

int cross(xy a, xy b) {
	int flag = a.x * b.y - a.y * b.x;

	if (flag < 0) return -1;
	else if (flag > 0) return 1;
	else return 0;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: CCW
결정적 깨달음		: 
시간복잡도		: 
오답 원인		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////