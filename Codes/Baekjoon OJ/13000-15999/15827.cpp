#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define ll long long

struct frac {
	ll mol, den;

	frac() : frac(0, 1) {}
	frac(ll m, ll d) : mol(m), den(d) {
		makeIrred(*this);
	}
	ll GCD(ll a, ll b) {
		if (b == 0) return a;
		else return GCD(b, a % b);
	}
	ll LCM(ll a, ll b) {
		ll gcd = GCD(a, b);
		return a * b / gcd;
	}
	tuple<ll, ll, ll> calFrac(frac x) {
		ll sden = LCM(abs(den), x.den);
		ll mol0 = mol * sden / den;
		ll mol1 = x.mol * sden / x.den;
		return make_tuple(mol0, mol1, sden);
	}
	void makeIrred(frac& x) {
		if (x.den < 0) {
			x.mol *= -1, x.den *= -1;
		}

		if (x.mol == 0) x.den = 1;
		else {
			ll gcd = GCD(abs(x.mol), x.den);
			x.mol /= gcd;
			x.den /= gcd;
		}
	}
	frac operator+(frac x) {
		frac ret;
		tuple<ll, ll, ll> c = calFrac(x);
		ret.mol = get<0>(c) + get<1>(c);
		ret.den = get<2>(c);
		makeIrred(ret);
		return ret;
	}
	frac operator-(frac x) {
		frac ret;
		tuple<ll, ll, ll> c = calFrac(x);
		ret.mol = get<0>(c) - get<1>(c);
		ret.den = get<2>(c);
		makeIrred(ret);
		return ret;
	}
	frac operator-() {
		return { -mol, den };
	}
	frac operator*(frac x) {
		frac ret;
		ret.mol = mol * x.mol;
		ret.den = den * x.den;
		makeIrred(ret);
		return ret;
	}
	frac operator/(frac x) {
		frac ret;
		ret.mol = mol * x.den;
		ret.den = den * x.mol;
		makeIrred(ret);
		return ret;
	}
	void print() {
		cout << mol << '/' << den;
	}
};

int N, hCnt, st;
map<string, int> Hash;
char cal[1005];
int par[1005], child[1005][2];
int depth[1005], mxDep;
frac w[1005];
frac influ[1005];

void input();
void getW();
void dfsDep(int now);
void dfsAns(int now);

int main() {
	cin.tie(NULL); cout.tie(NULL); 
	ios_base::sync_with_stdio(false);

	input();

	dfsDep(st);

	getW();

	influ[st].mol = influ[st].den = 1;
	dfsAns(st);

	for (auto& q : Hash) {
		cout << q.first << ' ';
		//w[q.second].print();
		influ[q.second].print();
		cout << '\n';
	}

	return 0;
}

void input() {
	cin >> N;

	struct factor {
		string name, c0, c1;
		char type;
	};

	factor Q[1005];

	for (int i = 0; i < N; i++) {
		cin >> Q[i].name >> Q[i].type;

		Hash.insert({ Q[i].name, ++hCnt });
		cal[hCnt] = Q[i].type;

		if (Q[i].type == 'E') cin >> w[hCnt].mol;
		else cin >> Q[i].c0 >> Q[i].c1;
	}

	st = Hash.find("HAPPY")->second;
	
	for (int i = 0; i < N; i++) {
		if (Q[i].type == 'E') continue;

		int now = Hash.find(Q[i].name)->second;
		int c0 = Hash.find(Q[i].c0)->second;
		int c1 = Hash.find(Q[i].c1)->second;

		child[now][0] = c0, child[now][1] = c1;
		par[c0] = now, par[c1] = now;
	}
}

void getW() {	
	queue<int> q;

	while (mxDep--) {
		for (int v = 1; v <= hCnt; v++) {
			if (depth[v] == mxDep) q.push(v);
		}

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			if (cal[now] == 'E') continue;

			int c0 = child[now][0], c1 = child[now][1];
			
			if (cal[now] == 'A') w[now] = w[c0] + w[c1];
			else if (cal[now] == 'S') w[now] = w[c0] - w[c1];
			else if (cal[now] == 'M') w[now] = w[c0] * w[c1];
			else if (cal[now] == 'D') w[now] = w[c0] / w[c1];
		}
	}
}

void dfsDep(int now) {
	depth[now] = depth[par[now]] + 1;

	mxDep = max(mxDep, depth[now]);

	if (cal[now] != 'E') {
		dfsDep(child[now][0]);
		dfsDep(child[now][1]);
	}
}

void dfsAns(int now) {	
	if (cal[now] == 'E') return;

	int c0 = child[now][0], c1 = child[now][1];

	if (cal[now] == 'A') {
		influ[c0] = influ[now];
		influ[c1] = influ[now];
	}
	else if (cal[now] == 'S') {
		influ[c0] = influ[now];
		influ[c1] = -influ[now];
	}
	else if (cal[now] == 'M') {
		influ[c0] = influ[now] * w[c1];
		influ[c1] = influ[now] * w[c0];
	}
	else if (cal[now] == 'D') {
		influ[c0] = influ[now] * frac(w[c1].den, w[c1].mol);
		influ[c1] = influ[now] * -w[c0] / (w[c1] * w[c1]);
	}

	dfsAns(c0);
	dfsAns(c1);
}