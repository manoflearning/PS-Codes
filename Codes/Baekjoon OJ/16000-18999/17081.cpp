#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const char dir[] = { 'R', 'L', 'U', 'D' };
const string effect[] = { "HR", "RE", "CO", "EX", "DX", "HU", "CU" };
const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct yx {
	int y, x;
};

struct monster{
	string name;
	int atk, def, hp, exp;
	monster() : monster("none", 0, 0, 0, 0) {}
	monster(string n, int a, int d, int h, int e) :
		name(n), atk(a), def(d), hp(h), exp(e) {}
};

struct item_box {
	char kind;
	int value;
	string effect;
};

struct character {
	int hp, atk, def, exp, max_hp;
	int weapon, armor;
	int jewCnt;
	bool jewelry[8];
	int level;
};

int R, C;
char arr[105][105];
bool isBossDead;
yx st, now;
string mov;
monster mon[105][105];
item_box box[105][105];
character hero;

void init();
void find_item_box(const int& ny, const int& nx);
void find_trap(const int& ny, const int& nx);
void find_monster(const int& ny, const int& nx);
void find_boss(const int& ny, const int& nx);
int jewNum(const string& name);
void level_up();
void revival();
bool end_of_game(const int& turn);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	init();

	for (int turn = 0; turn < mov.size(); turn++) {
		int d = find(dir, dir + 3, mov[turn]) - dir;
		int ny = now.y + dy[d], nx = now.x + dx[d];

		if (ny < 1 || R < ny || nx < 1 || C < nx || arr[ny][nx] == '#') ny = now.y, nx = now.x;
		
		if (arr[ny][nx] == 'B') find_item_box(ny, nx);
		else if (arr[ny][nx] == '^') find_trap(ny, nx);
		else if (arr[ny][nx] == '&') find_monster(ny, nx);
		else if (arr[ny][nx] == 'M') find_boss(ny, nx);

		now = { ny, nx };
		level_up();
		revival();

		if (end_of_game(turn)) break;
	}

	return 0;
}

void init() {
	int mCnt = 0, bCnt = 0;

	cin >> R >> C;
	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			cin >> arr[y][x];

			if (arr[y][x] == '&' || arr[y][x] == 'M') mCnt++;
			else if (arr[y][x] == 'B') bCnt++;
			else if (arr[y][x] == '@') {
				st = now = { y, x };
				arr[y][x] = '.';
			}
		}
	}

	cin >> mov;

	while (mCnt--) {
		int y, x, a, d, f, e;
		string n;
		cin >> y >> x >> n >> a >> d >> f >> e;
		mon[y][x] = monster(n, a, d, f, e);
	}

	while (bCnt--) {
		int y, x;
		char T;
		cin >> y >> x >> T;

		box[y][x].kind = T;

		if (T == 'W' || T == 'A') {
			int N; cin >> N;
			box[y][x].value = N;
		}
		else if (T == 'O') {
			string s; cin >> s;
			box[y][x].effect = s;
		}
	}

	hero.hp = hero.max_hp = 20, hero.atk = 2, hero.def = 2, hero.level = 1;
}

void find_item_box(const int& ny, const int& nx) {
	if (box[ny][nx].kind == 'W') hero.weapon = box[ny][nx].value;
	else if (box[ny][nx].kind == 'A') hero.armor = box[ny][nx].value;
	else if (box[ny][nx].kind == 'O') {
		if (hero.jewCnt >= 4);
		else if (hero.jewelry[jewNum(box[ny][nx].effect)]);
		else {
			hero.jewCnt++;
			hero.jewelry[jewNum(box[ny][nx].effect)] = true;
		}
	}

	arr[ny][nx] = '.';
}

void find_trap(const int& ny, const int& nx) {
	if (hero.jewelry[jewNum("DX")]) hero.hp -= 1;
	else hero.hp -= 5;
}

void find_monster(const int& ny, const int& nx) {
	int mon_max_hp = mon[ny][nx].hp;

	for (int i = 1; ; i++) {
		if (i == 1 && hero.jewelry[jewNum("CO")]) {
			if(hero.jewelry[jewNum("DX")])
				mon[ny][nx].hp -= max(1, 3 * (hero.atk + hero.weapon) - mon[ny][nx].def);
			else mon[ny][nx].hp -= max(1, 2 * (hero.atk + hero.weapon) - mon[ny][nx].def);
		}
		else mon[ny][nx].hp -= max(1, (hero.atk + hero.weapon) - mon[ny][nx].def);

		if (mon[ny][nx].hp <= 0) break;
		
		if (i == 1 && arr[ny][nx] == 'M' && hero.jewelry[jewNum("HU")]) continue;
		hero.hp -= max(1, mon[ny][nx].atk - (hero.def + hero.armor));
		
		if (hero.hp <= 0) break;
	}

	if (mon[ny][nx].hp <= 0) {
		if (hero.jewelry[jewNum("HR")]) 
			hero.hp = min(hero.hp + 3, hero.max_hp);
		arr[ny][nx] = '.';

		if (hero.jewelry[jewNum("EX")])
			hero.exp += (int)(1.2 * mon[ny][nx].exp);
		else hero.exp += mon[ny][nx].exp;
	}
	else if (hero.hp <= 0) {
		mon[ny][nx].hp = mon_max_hp;
	}
}

void find_boss(const int& ny, const int& nx) {
	if (hero.jewelry[jewNum("HU")]) hero.hp = hero.max_hp;

	find_monster(ny, nx);

	if (mon[ny][nx].hp <= 0) isBossDead = true;
}
int jewNum(const string& name) {
	return find(effect, effect + 8, name) - effect;
}

void level_up() {
	if (hero.exp >= 5 * hero.level) {
		hero.level++;
		hero.max_hp += 5;
		hero.atk += 2, hero.def += 2;
		hero.hp = hero.max_hp;
		hero.exp = 0;
	}
}

void revival() {
	if (hero.hp <= 0 && hero.jewelry[jewNum("RE")]) {
		hero.jewelry[jewNum("RE")] = false;
		hero.jewCnt -= 1;
		hero.hp = hero.max_hp;
		now = st;
	}
}

bool end_of_game(const int& turn) {
	if (!(turn == mov.size() - 1 || hero.hp <= 0 || isBossDead)) return false;

	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			if (hero.hp > 0 && now.y == y && now.x == x) cout << '@';
			else cout << arr[y][x];
		}
		cout << '\n';
	}

	cout << "Passed Turns : " << turn + 1 << '\n';
	cout << "LV : " << hero.level << '\n';
	cout << "HP : " << max(0, hero.hp) << '/' << hero.max_hp << '\n';
	cout << "ATT : " << hero.atk << '+' << hero.weapon << '\n';
	cout << "DEF : " << hero.def << '+' << hero.armor << '\n';
	cout << "EXP : " << hero.exp << '/' << 5 * hero.level << '\n';
	//cout << now.y << ' ' << now.x << "\n\n";
	//if (!(turn == mov.size() - 1 || hero.hp <= 0 || isBossDead)) return false;
	if (isBossDead) cout << "YOU WIN!\n";
	else if (hero.hp <= 0) {
		cout << "YOU HAVE BEEN KILLED BY ";
		if (arr[now.y][now.x] == '^') cout << "SPIKE TRAP..\n";
		else cout << mon[now.y][now.x].name << "..\n";
	}
	else if (turn == mov.size() - 1) cout << "Press any key to continue.\n";

	return true;
}