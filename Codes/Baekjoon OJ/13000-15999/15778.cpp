#include <iostream>
#include <set>
#include <vector>
#define pii pair<int, int>
using namespace std;

struct yut {
	int y, x;
	yut() : yut(0, 0) {}
	yut(int sy, int sx) : y(sy), x(sx) {}
};

struct yx {
	int y, x;
	yx() : yx(0, 0) {}
	yx(int sy, int sx) : y(sy), x(sx) {}
};

vector<yut> A(4), a(4);
vector<vector<set<char>>> A_road(8, vector<set<char>>(8)), a_road(8, vector<set<char>>(8));
vector<string> ans(32);

int numOfMove();
void simul(int movCnt, int yutNum, char name, vector<yut>& ally, vector<yut>& enemy, vector<vector<set<char>>>& a_road, vector<vector<set<char>>>& e_road);
yx moving(int movCnt, yut& hero);
void print();
void draw(yut& n, int i, char name);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	for (int i = 0; i < 4; i++) {
		A_road[0][i].insert(i + 'A');
		A[i] = yut(0, i);
		a_road[0][i].insert(i + 'a');
		a[i] = yut(0, i);
	}

	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		char name; cin >> name;
		int movCnt = numOfMove();

		if ('a' <= name)
			simul(movCnt, name - 'a', name, a, A, a_road, A_road);
		else
			simul(movCnt, name - 'A', name, A, a, A_road, a_road);			
	}

	print();

	return 0;
}

int numOfMove() {
	string mov; cin >> mov;

	int ret = 0;
	for (char i : mov)
		if (i == 'F') ret++;

	return ret == 0 ? 5 : ret;
}

void simul(int movCnt, int yutNum, char name, vector<yut>& ally, vector<yut>& enemy, vector<vector<set<char>>>& a_road, vector<vector<set<char>>>& e_road) {
	yut& hero = ally[yutNum];

	yx now = { hero.y, hero.x }, next = moving(movCnt, hero);

	for (auto i : a_road[now.y][now.x]) {
		a_road[next.y][next.x].insert(i);
		
		ally[('a' <= i) ? i - 'a' : i - 'A'].y = next.y;
		ally[('a' <= i) ? i - 'a' : i - 'A'].x = next.x;
	}
	a_road[now.y][now.x].clear();
	
	for (auto i : e_road[next.y][next.x]) {
		enemy[('a' <= i) ? i - 'a' : i - 'A'].y = 0;
		enemy[('a' <= i) ? i - 'a' : i - 'A'].x = ('a' <= i) ? i - 'a' : i - 'A';
		e_road[0][('a' <= i) ? i - 'a' : i - 'A'].insert(i);
	}
	e_road[next.y][next.x].clear();
}

yx moving(int movCnt, yut& hero) {
	pii ret = { hero.y, hero.x };
	
	if (ret.first == 0 || ret.second == 0) {
		if (movCnt <= 4) ret = make_pair(7 - movCnt, 7);
		else ret = make_pair(1, 7);
	}
	else if (ret == make_pair(1, 1)) {
		ret = make_pair(1 + movCnt, 1 + movCnt);
	}
	else if (ret == make_pair(1, 3)) {
		ret = make_pair(movCnt, 1);
	}
	else if (ret == make_pair(1, 4)) {
		if (movCnt <= 1) ret = make_pair(1, 4 - movCnt);
		else ret = make_pair(movCnt - 1, 1);
	}
	else if (ret == make_pair(1, 5)) {
		if (movCnt <= 2) ret = make_pair(1, 5 - movCnt);
		else ret = make_pair(movCnt - 2, 1);
	}
	else if (ret == make_pair(1, 6)) {
		if (movCnt <= 3) ret = make_pair(1, 6 - movCnt);
		else ret = make_pair(movCnt - 3, 1);
	}
	else if (ret == make_pair(1, 7)) {
		ret = make_pair(1 + movCnt, 7 - movCnt);
	}
	else if (ret == make_pair(2, 1)) {
		if (movCnt <= 3) ret = make_pair(2 + movCnt, 1);
		else ret = make_pair(7, movCnt - 3);
	}
	else if (ret == make_pair(2, 2)) {
		ret = make_pair(2 + movCnt, 2 + movCnt);
	}
	else if (ret == make_pair(2, 6)) {
		ret = make_pair(2 + movCnt, 6 - movCnt);
	}
	else if (ret == make_pair(3, 1)) {
		if (movCnt <= 2) ret = make_pair(3 + movCnt, 1);
		else ret = make_pair(7, movCnt - 2);
	}
	else if (ret == make_pair(3, 3)) {
		if (movCnt <= 4) ret = make_pair(3 + movCnt, 3 + movCnt);
		else ret = make_pair(1, 0);
	}
	else if (ret == make_pair(3, 5)) {
		if (movCnt <= 4) ret = make_pair(3 + movCnt, 5 - movCnt);
		else ret = make_pair(7, 2);
	}
	else if (ret == make_pair(3, 7)) {
		ret = make_pair(1, 8 - movCnt);
	}
	else if (ret == make_pair(4, 1)) {
		if (movCnt <= 1) ret = make_pair(4 + movCnt, 1);
		else ret = make_pair(7, movCnt - 1);
	}
	else if (ret == make_pair(4, 4)) {
		if (movCnt <= 3) ret = make_pair(4 + movCnt, 4 + movCnt);
		else ret = make_pair(1, 0);
	}
	else if (ret == make_pair(4, 7)) {
		if (movCnt <= 1) ret = make_pair(4 - movCnt, 7);
		else ret = make_pair(1, 9 - movCnt);
	}
	else if (ret == make_pair(5, 1)) {
		ret = make_pair(7, movCnt);
	}
	else if (ret == make_pair(5, 3)) {
		if (movCnt <= 1) ret = make_pair(5 + movCnt, 3 - movCnt);
		else ret = make_pair(7, movCnt - 1);
	}
	else if (ret == make_pair(5, 5)) {
		if (movCnt <= 2) ret = make_pair(5 + movCnt, 5 + movCnt);
		else ret = make_pair(1, 0);
	}
	else if (ret == make_pair(5, 7)) {
		if (movCnt <= 2) ret = make_pair(5 - movCnt, 7);
		else ret = make_pair(1, 10 - movCnt);
	}
	else if (ret == make_pair(6, 2)) {
		ret = make_pair(7, movCnt);
	}
	else if (ret == make_pair(6, 6)) {
		if (movCnt <= 1) ret = make_pair(6 + movCnt, 6 + movCnt);
		else ret = make_pair(1, 0);
	}
	else if (ret == make_pair(6, 7)) {
		if (movCnt <= 3) ret = make_pair(6 - movCnt, 7);
		else ret = make_pair(1, 11 - movCnt);
	}
	else if (ret == make_pair(7, 1)) {
		if (movCnt <= 4) ret = make_pair(7, 1 + movCnt);
		else ret = make_pair(7, 7);
	}
	else if (ret == make_pair(7, 2)) {
		if (movCnt <= 3) ret = make_pair(7, 2 + movCnt);
		else if (movCnt <= 4) ret = make_pair(7, 7);
		else ret = make_pair(1, 0);
	}
	else if (ret == make_pair(7, 3)) {
		if (movCnt <= 2) ret = make_pair(7, 3 + movCnt);
		else if (movCnt <= 3) ret = make_pair(7, 7);
		else ret = make_pair(1, 0);
	}
	else if (ret == make_pair(7, 4)) {
		if (movCnt <= 1) ret = make_pair(7, 4 + movCnt);
		else if (movCnt <= 2) ret = make_pair(7, 7);
		else ret = make_pair(1, 0);
	}
	else if (ret == make_pair(7, 5)) {
		if (movCnt <= 1) ret = make_pair(7, 7);
		else ret = make_pair(1, 0);
	}
	else if (ret == make_pair(7, 7)) {
		ret = make_pair(1, 0);
	}

	return { ret.first, ret.second };
}

void print() {
	ans[0] = "..----..----..----..----..----..";
	ans[1] = "..    ..    ..    ..    ..    ..";
	ans[2] = "| \\                          / |";
	ans[3] = "|  \\                        /  |";
	ans[4] = "|   \\                      /   |";
	ans[5] = "|    ..                  ..    |";
	ans[6] = "..   ..                  ..   ..";
	ans[7] = "..     \\                /     ..";
	ans[8] = "|       \\              /       |";
	ans[9] = "|        \\            /        |";
	ans[10] = "|         ..        ..         |";
	ans[11] = "|         ..        ..         |";
	ans[12] = "..          \\      /          ..";
	ans[13] = "..           \\    /           ..";
	ans[14] = "|             \\  /             |";
	ans[15] = "|              ..              |";
	ans[16] = "|              ..              |";
	ans[17] = "|             /  \\             |";
	ans[18] = "..           /    \\           ..";
	ans[19] = "..          /      \\          ..";
	ans[20] = "|         ..        ..         |";
	ans[21] = "|         ..        ..         |";
	ans[22] = "|        /            \\        |";
	ans[23] = "|       /              \\       |";
	ans[24] = "..     /                \\     ..";
	ans[25] = "..   ..                  ..   ..";
	ans[26] = "|    ..                  ..    |";
	ans[27] = "|   /                      \\   |";
	ans[28] = "|  /                        \\  |";
	ans[29] = "| /                          \\ |";
	ans[30] = "..    ..    ..    ..    ..    ..";
	ans[31] = "..----..----..----..----..----..";
	
	for (char i = 0; i < 4; i++) {
		draw(A[i], i, 'A' + i);
		draw(a[i], i, 'a' + i);
	}
	
	for (int i = 0; i < 32; i++)
		cout << ans[i] << '\n';
}

void draw(yut& n, int i, char name) {
	pii pos = { n.y, n.x };

	yx key;
	
	if (pos.first == 0 || pos.second == 0) return;
	else if (pos == make_pair(1, 1)) key = yx(0, 0);
	else if (pos == make_pair(1, 3)) key = yx(0, 6);
	else if (pos == make_pair(1, 4)) key = yx(0, 12);
	else if (pos == make_pair(1, 5)) key = yx(0, 18);
	else if (pos == make_pair(1, 6)) key = yx(0, 24);
	else if (pos == make_pair(1, 7)) key = yx(0, 30);
	else if (pos == make_pair(2, 2)) key = yx(5, 5);
	else if (pos == make_pair(2, 6)) key = yx(5, 25);
	else if (pos == make_pair(2, 1)) key = yx(6, 0);
	else if (pos == make_pair(3, 7)) key = yx(6, 30);
	else if (pos == make_pair(3, 3)) key = yx(10, 10);
	else if (pos == make_pair(3, 5)) key = yx(10, 20);
	else if (pos == make_pair(3, 1)) key = yx(12, 0);
	else if (pos == make_pair(4, 7)) key = yx(12, 30);
	else if (pos == make_pair(4, 4)) key = yx(15, 15);
	else if (pos == make_pair(4, 1)) key = yx(18, 0);
	else if (pos == make_pair(5, 7)) key = yx(18, 30);
	else if (pos == make_pair(5, 3)) key = yx(20, 10);
	else if (pos == make_pair(5, 5)) key = yx(20, 20);
	else if (pos == make_pair(5, 1)) key = yx(24, 0);
	else if (pos == make_pair(6, 7)) key = yx(24, 30);
	else if (pos == make_pair(6, 2)) key = yx(25, 5);
	else if (pos == make_pair(6, 6)) key = yx(25, 25);
	else if (pos == make_pair(7, 1)) key = yx(30, 0);
	else if (pos == make_pair(7, 2)) key = yx(30, 6);
	else if (pos == make_pair(7, 3)) key = yx(30, 12);
	else if (pos == make_pair(7, 4)) key = yx(30, 18);
	else if (pos == make_pair(7, 5)) key = yx(30, 24);
	else if (pos == make_pair(7, 7)) key = yx(30, 30);
	/*if (pos.first == 0 || pos.second == 0) return;
	else if (pos == make_pair(1, 1)) key = yx(0, 0);
	else if (pos == make_pair(1, 3)) key = yx(0, 6);
	else if (pos == make_pair(1, 4)) key = yx(0, 12);
	else if (pos == make_pair(1, 5)) key = yx(0, 18);
	else if (pos == make_pair(1, 6)) key = yx(0, 24);
	else if (pos == make_pair(1, 7)) key = yx(0, 30);
	else if (pos == make_pair(2, 1)) key = yx(6, 0);
	else if (pos == make_pair(2, 2)) key = yx(5, 5);
	else if (pos == make_pair(2, 6)) key = yx(5, 25);
	else if (pos == make_pair(3, 1)) key = yx(12, 0);
	else if (pos == make_pair(3, 3)) key = yx(10, 10);
	else if (pos == make_pair(3, 5)) key = yx(10, 20);
	else if (pos == make_pair(3, 7)) key = yx(6, 30);
	else if (pos == make_pair(4, 1)) key = yx(18, 0);
	else if (pos == make_pair(4, 4)) key = yx(15, 15);
	else if (pos == make_pair(4, 7)) key = yx(12, 30);
	else if (pos == make_pair(5, 1)) key = yx(24, 0);
	else if (pos == make_pair(5, 3)) key = yx(20, 10);
	else if (pos == make_pair(5, 5)) key = yx(20, 20);
	else if (pos == make_pair(5, 7)) key = yx(18, 30);
	else if (pos == make_pair(6, 2)) key = yx(25, 5);
	else if (pos == make_pair(6, 6)) key = yx(25, 25);
	else if (pos == make_pair(6, 7)) key = yx(24, 30);
	else if (pos == make_pair(7, 1)) key = yx(30, 0);
	else if (pos == make_pair(7, 2)) key = yx(30, 6);
	else if (pos == make_pair(7, 3)) key = yx(30, 12);
	else if (pos == make_pair(7, 4)) key = yx(30, 18);
	else if (pos == make_pair(7, 5)) key = yx(30, 24);
	else if (pos == make_pair(7, 7)) key = yx(30, 30);*/
	
	if (i == 0) ans[key.y][key.x] = name;
	else if (i == 1) ans[key.y][key.x + 1] = name;
	else if (i == 2) ans[key.y + 1][key.x] = name;
	else if (i == 3) ans[key.y + 1][key.x + 1] = name;
}