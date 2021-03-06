#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXV = 100;
const int INF = 1e9 + 7;

int N, R, M, K;
map<string, int> Hash;
int hCnt;
int path[2 * MAXV + 5];
double adj1[MAXV + 5][MAXV + 5], adj2[MAXV + 5][MAXV + 5];

void init();
void input();
void floyd(double adj[][MAXV + 5]);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	init();

	input();

	floyd(adj1);
	floyd(adj2);

	double cost1 = 0, cost2 = R;
	for (int i = 1; i < M; i++) {
		cost1 += adj1[path[i - 1]][path[i]];
		cost2 += adj2[path[i - 1]][path[i]];
		//cout << adj1[path[i - 1]][path[i]] << '\n';
	}

	/*cout << adj2[Hash.find("Seoul")->second][Hash.find("Cheonan")->second] << ' ';
	cout << adj2[Hash.find("Cheonan")->second][Hash.find("Daejeon")->second] << ' ';
	cout << adj2[Hash.find("Daejeon")->second][Hash.find("Gwangju")->second] << ' ';
	cout << adj2[Hash.find("Gwangju")->second][Hash.find("Jeonju")->second] << ' ';*/

	if (cost1 <= cost2) cout << "No";
	else cout << "Yes";

	return 0;
}

void init() {
	for (int i = 0; i < MAXV + 5; i++) {
		for (int l = 0; l < MAXV + 5; l++) {
			adj1[i][l] = adj2[i][l] = INF;
		}
	}
}

void input() {
	cin >> N >> R;

	for (int i = 0; i < N; i++) {
		string s; cin >> s;

		auto it = Hash.find(s);
		if (it == Hash.end()) Hash.insert({ s, ++hCnt });
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		string s; cin >> s;
		path[i] = Hash.find(s)->second;
	}

	cin >> K;

	for (int i = 0; i < K; i++) {
		string type, S, E;
		double cost;
		cin >> type >> S >> E >> cost;

		int st = Hash.find(S)->second, en = Hash.find(E)->second;

		adj1[st][en] = adj1[en][st] = min<double>(adj1[st][en], cost);

		if (type == "Mugunghwa" || type == "ITX-Saemaeul" || type == "ITX-Cheongchun") {
			adj2[st][en] = adj2[en][st] = min<double>(adj2[st][en], 0);
		}
		else if (type == "S-Train" || type == "V-Train") {
			adj2[st][en] = adj2[en][st] = min<double>(adj2[st][en], cost / 2);
		}
		else adj2[st][en] = adj2[en][st] = min<double>(adj2[st][en], cost);
	}
}

void floyd(double adj[][MAXV + 5]) {
	for (int i = 1; i <= hCnt; i++) adj[i][i] = 0;

	for (int k = 1; k <= hCnt; k++) {
		for (int u = 1; u <= hCnt; u++) {
			for (int v = 1; v <= hCnt; v++) {
				adj[u][v] = min(adj[u][v], adj[u][k] + adj[k][v]);
			}
		}
	}
}