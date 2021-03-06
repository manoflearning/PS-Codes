#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = pow(10, 9);

long long k, c;

void ext_gcd(long long s0, long long s1, long long t0, long long t1, long long r0, long long r1);

int main() {
	int t;
	cin >> t;

	for (int test = 0; test < t; test++) {
		cin >> k >> c;
		
		ext_gcd(1, 0, 0, 1, k, c);
	}

	return 0;
}

void ext_gcd(long long s0, long long s1, long long t0, long long t1, long long r0, long long r1) {
	long long r2 = r0 % r1;

	if (r2 == 0) {
		if (r1 == 1) {
			t1 = (t1 + k) % k;
			if (t1 == 0) t1 = 1;
			if (s1 == 0) t1 += k;

			if (t1 > MAX) cout << "IMPOSSIBLE\n";
			else cout << t1 << '\n';
		}
		else cout << "IMPOSSIBLE\n";
	}
	else {
		long long q = r0 / r1;
		ext_gcd(s1, s0 - s1 * q, t1, t0 - t1 * q, r1, r2);
	}
}
/*//////////////////////////////////////////////////////////////////////
문제 해법		: 확장 유클리드 호제법
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 
				  2. 
*///////////////////////////////////////////////////////////////////////