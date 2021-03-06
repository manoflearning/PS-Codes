#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 500;
const int INF = 1e9 + 7;

struct wv {
	int w, v;
};

int N, upper[MAX + 5];
vector<wv> adj[MAX + 5];

void init();
void input();
bool bellmanFord();

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;

	while (T--) {
		init();

		input();

		if (bellmanFord()) cout << "NO\n";
		else cout << "YES\n";
	}

	return 0;
}

void init() {
	for (auto& i : adj) i.clear();
}

void input() {
	int M, W;
	cin >> N >> M >> W;

	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
		adj[v].push_back({ w, u });
	}

	for (int i = 0; i < W; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ -w, v });
	}
}

bool bellmanFord() {
	fill(upper, upper + MAX + 5, INF);

	upper[1] = 0;

	bool update = true;
	for (int i = 0; i < N; i++) {
		update = false;
		for (int u = 1; u <= N; u++) {
			//if (upper[u] == INF) continue;
			for (auto e : adj[u]) {
				int v = e.v;
				if (upper[v] > upper[u] + e.w) {
					upper[v] = upper[u] + e.w;
					update = true;
				}
			}
		}
	}

	return !update;
}