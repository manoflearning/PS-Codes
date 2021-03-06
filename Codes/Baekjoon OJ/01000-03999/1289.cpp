#define _USE_MATH_DEFINES
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };
const int MAX = 1e5;

struct wv{
    ll w;
    int v;
};

int n;
vector<wv> adj[MAX+5];
ll res;

ll dfs(int v, int prv){
    ll ret=0;
    
    vector<ll> arr;
    for(auto& i : adj[v]){
        if(i.v==prv) continue;
        arr.push_back((i.w+i.w*dfs(i.v, v))%MOD);
    }
    
    for(ll& i : arr){
        res+=i*ret;
        res%=MOD;
        ret+=i;
        ret%=MOD;
    }
    
    res+=ret;
    res%=MOD;
    
    return ret;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=0; i<n-1; i++){
        int a, b, w;
        cin>>a>>b>>w;
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }
    
    dfs(1, 0);
    
    cout<<res;
    
    return 0;
}
