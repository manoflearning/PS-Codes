//naive
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };
const int MAX = 1e6;

int n;
bool isPrime[MAX + 5], visited[MAX + 5];
vector<int> prime(1, 2), adj[MAX + 5];

void getPrime() {
	fill(isPrime, isPrime + n + 1, true);

	for (ll i = 4; i <= n; i += 2)
		isPrime[i] = false;
	for (ll i = 3; i <= n; i++) {
	    if (isPrime[i]) prime.push_back(i);
		for (ll j = i * i; j <= n; j += i * 2) 
		    isPrime[j] = false;
	}
}

void naive() {    
    for (int i : prime) {
        set<int> s;
        int val = i, b = 0;
        
        while (1) {
            int div = 1, sum = 0;
	        while (val >= div) {
	            sum += (val / div % 10) * (val / div % 10);
	            div *= 10;
	        }
	        
	        val = sum;
	        
	        if (val == 1) { b = 1; break; }
	        if (s.find(val) != s.end()) break;
	        
	        s.insert(val);
        }
        
        if (b) cout << i << '\n';
    }
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	
	getPrime();
	
	naive();
	
	return 0;
}


//graph modeling
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };
const int MAX = 1e6;

int n;
bool isPrime[MAX + 5], visited[MAX + 5];
vector<int> prime(1, 2), adj[MAX + 5];

void getPrime() {
	fill(isPrime, isPrime + MAX + 1, true);

	for (ll i = 4; i <= MAX; i += 2)
		isPrime[i] = false;
	for (ll i = 3; i <= MAX; i++) {
	    if (isPrime[i]) prime.push_back(i);
		for (ll j = i * i; j <= MAX; j += i * 2) 
		    isPrime[j] = false;
	}
}

void modeling() {	
    cin >> n;
    
	for (int val = 2; val <= MAX; val++) {
	    int div = 1, sum = 0;
	    while (val >= div) {
	        sum += (val / div % 10) * (val / div % 10);
	        div *= 10;
	    }
	    
	    adj[sum].push_back(val);
	}
}

void dfs(int v) {
    visited[v] = 1;
    for (int i : adj[v]) {
        if (!visited[i]) dfs(i);
    }
}

void print() {
    for (int i = 2; i <= n; i++) {
        if (isPrime[i] && visited[i])
            cout << i << '\n';
    }    
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	getPrime();
	
	modeling();
	
	dfs(1);
	
	print();

	return 0;
}


//graph modeling on interval [1, 6 * 81]
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };
const int MAX = 1e6;
const int C = 6 * 81;

int n;
bool isPrime[MAX + 5], visited[C + 5];
vector<int> prime(1, 2), adj[C + 5];

void getPrime() {
	fill(isPrime, isPrime + n + 1, true);

	for (ll i = 4; i <= n; i += 2)
		isPrime[i] = false;
	for (ll i = 3; i <= n; i++) {
	    if (isPrime[i]) prime.push_back(i);
		for (ll j = i * i; j <= n; j += i * 2) 
		    isPrime[j] = false;
	}
}

void modeling() {	    
	for (int i = 2; i <= C; i++) {
	    int val = i, sum = 0;
	    while (val) {
	        sum += (val % 10) * (val % 10);
	        val /= 10;
	    }
	    
	    adj[sum].push_back(i);
	}
}

void dfs(int v) {
    visited[v] = 1;
    for (int i : adj[v]) {
        if (!visited[i]) dfs(i);
    }
}

void print() {
    for (int p : prime) {        
        int val = 0;
        
        if (p > C) {
            int div = 1;
            while (p >= div) {
	            val += (p / div % 10) * (p / div % 10);
	            div *= 10;
	        }
        }
        else val = p;
        
        if (visited[val]) cout << p << '\n';
    }    
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	
	getPrime();
	
	modeling();
	
	dfs(1);
	
	print();

	return 0;
}
