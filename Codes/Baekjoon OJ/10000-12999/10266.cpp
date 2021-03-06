#define _USE_MATH_DEFINES
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int INF = 1e9 + 7;
const int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9, MOD3 = 99999999;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };
const int d = 360000;

int n;
ll d1, d2, d3, o1, o2, o3;
vector<int> a, b;

void input() {
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
}

void pre() {
    d1 = d2 = d3 = d;
    o1 = o2 = o3 = 1;
    for (int i = 1; i < n; i++) {
        d1 = d * d1 % MOD1;
        d2 = d * d2 % MOD2;
        d3 = d * d3 % MOD3;
        o1 = (d * o1 + 1) % MOD1;
        o2 = (d * o2 + 1) % MOD2;
        o3 = (d * o3 + 1) % MOD3;
    }
    
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
}

int rabinKarp() {
    ll a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
    
    for (int i = 0; i < n; i++) {
        a1 = (d * a1 + a[i]) % MOD1;
        a2 = (d * a2 + a[i]) % MOD2;
        a3 = (d * a3 + a[i]) % MOD3;
        b1 = (d * b1 + b[i]) % MOD1;
        b2 = (d * b2 + b[i]) % MOD2;
        b3 = (d * b3 + b[i]) % MOD3;
    }
    
    if (a1 == b1 && a2 == b2 && a3 == b3) return 1;
    
    int idx = 0;
    for (int i = 1; i < d; i++) {
        a1 = (a1 + o1) % MOD1;
        a2 = (a2 + o2) % MOD2;
        a3 = (a3 + o3) % MOD3;
        
        if (idx < n && a[idx] + i == d) {
            a1 = (d * (a1 - d1)) % MOD1;
            a2 = (d * (a2 - d2)) % MOD2;
            a3 = (d * (a3 - d3)) % MOD3;
            a1 = (a1 + MOD1) % MOD1;
            a2 = (a2 + MOD2) % MOD2;
            a3 = (a3 + MOD3) % MOD3;
            idx++;
        }
        
        if (a1 == b1 && a2 == b2 && a3 == b3) return 1;
    }
    
    return 0;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    input();
    
    pre();
    
    if (rabinKarp()) cout << "possible";
    else cout << "impossible";
    
    return 0;
}
