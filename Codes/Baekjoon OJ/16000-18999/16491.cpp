#include <iostream>
using namespace std;

struct xy {
	int x; int y;
};

int N, p[10];
xy r[10], s[10];
bool visited[10];

void pick(int flag);
bool isnotMeet();
bool isMeet(xy a, xy b, xy c, xy d);
int CCW(xy a, xy b, xy c);
void print();

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> r[i].x >> r[i].y;
	for (int i = 0; i < N; i++)
		cin >> s[i].x >> s[i].y;

	pick(0);

	return 0;
}

void pick(int flag) {
	static bool first = true;
	if (flag >= N) {
		if (first && isnotMeet()) {
			first = false;
			print();
		}
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		
		p[flag] = i;
		visited[i] = true;
		pick(flag + 1);
		visited[i] = false;
	}
}
bool isnotMeet() {
	for (int i = 0; i < N; i++) {
		for (int l = i + 1; l < N; l++) {
			if (isMeet(r[i], s[p[i]], r[l], s[p[l]])) return false;
		}
	}
	return true;
}
bool isMeet(xy a, xy b, xy c, xy d) {
	int ab = CCW(a, b, c) * CCW(a, b, d);
	int cd = CCW(c, d, a) * CCW(c, d, b);

	if (ab <= 0 && cd <= 0) {
		if (ab == 0 && cd == 0) {
			pair<int, int> A = { a.x, a.y }, B = { b.x, b.y }, C = { c.x, c.y }, D = { d.x, d.y };
			if (A > B) swap(A, B);
			if (C > D) swap(C, D);
			return A <= D && C <= B;
		}
		return true;
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
void print() {
	for (int i = 0; i < N; i++)
		cout << p[i] + 1 << '\n';
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: CCW. 가능한 모든 로봇과 대피소의 조합 만들기. 각각의 조합에서 어떠한 직선도 교차하지 않는지 판별.
결정적 깨달음		: 
시간복잡도		: O(n! * n^2)
오답 원인		: 1.  
				  2.
*/////////////////////////////////////////////////////////////////////