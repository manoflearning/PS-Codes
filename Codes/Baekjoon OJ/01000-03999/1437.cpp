#define _USE_MATH_DEFINES
//#include <bits/stdc++.h>
#include <iostream>
#include <cassert>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int INF = 1e9 + 7;
const int MOD = 1e4 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };
const int MAX = 1e6;

int p3[MAX + 5];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    p3[0] = 1;
    for (int i = 1; i <= MAX; i++) {
        p3[i] = 3 * p3[i - 1] % MOD;
    }
    
    int n; cin >> n;
    
    if (n < 3) cout << n;
    else if (n % 3 == 1) cout << 4 * p3[(n - 4) / 3] % MOD; 
    else if (n % 3 == 2) cout << 2 * p3[(n - 2) / 3] % MOD;
    else if (n % 3 == 0) cout << p3[n / 3];
    
    return 0;
}
