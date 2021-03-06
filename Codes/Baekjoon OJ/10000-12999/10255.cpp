#include <iostream>
using namespace std;

struct xy {
	int x; int y;
};

int overlap = 0;
bool unlimited = false;

inline pair<int, int> oper(xy n);
bool isMeet(xy a, xy b, xy c, xy d);
int CCW(xy a, xy b, xy c);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;

	while (T--) {
		unlimited = false;
		overlap = 0;

		xy mn, mx, xy1, xy2;
		cin >> mn.x >> mn.y >> mx.x >> mx.y;
		cin >> xy1.x >> xy1.y >> xy2.x >> xy2.y;

		int ans = 0;

		if (isMeet(mn, { mn.x, mx.y }, xy1, xy2)) ans++;
		if (isMeet(mn, { mx.x, mn.y }, xy1, xy2)) ans++;
		if (isMeet({ mn.x, mx.y }, mx, xy1, xy2)) ans++;
		if (isMeet({ mx.x, mn.y }, mx, xy1, xy2)) ans++;
		
		ans -= (overlap / 2);
		
		if (unlimited) cout << 4 << '\n';
		else cout << ans << '\n';
	}

	return 0;
}

inline pair<int, int> oper(xy n) {
	return { n.x, n.y };
}
bool isMeet(xy a, xy b, xy c, xy d) {
	int ab = CCW(a, b, c) * CCW(a, b, d);
	int cd = CCW(c, d, a) * CCW(c, d, b);

	if (ab <= 0 && cd <= 0) {
		if (ab == 0 && cd == 0) {
			if (CCW(a, b, c) == 0 && CCW(a, b, d) == 0) {
				pair<int, int> A = oper(a), B = oper(b), C = oper(c), D = oper(d);
				if (A > B) swap(A, B);
				if (C > D) swap(C, D);

				if (A <= D && C <= B) {
					if (A == D || C == B) {
						overlap++;
						return true;
					}
					else {
						unlimited = true;
						return true;
					}
				}
				else return false;
			}
			else {
				overlap++;
				return true;
			}
		}
		else {
			if (cd == 0) overlap++;
			
			return true;
		}
	}
 	else return false;
}
int CCW(xy a, xy b, xy c) {
	xy A = { b.x - a.x, b.y - a.y }, B = { c.x - a.x, c.y - a.y };
	int flag = A.x * B.y - A.y * B.x;
	
	if (flag > 0) return 1;
	if (flag < 0) return -1;
	return 0;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: CCW
결정적 깨달음		: 
시간복잡도		: 
오답 원인		: 1. 예외처리 
				  2.
*/////////////////////////////////////////////////////////////////////