#define _USE_MATH_DEFINES
//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <set>
#include <cassert>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll INF = (ll)1e18 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };
const int MAX = 1e5;

struct dv{
    ll d; 
    int v;
};

bool operator<(dv a, dv b) {
    return a.d > b.d;
}

int n, m, st, en;
ll c;
vector<dv> adj[MAX+5];
vector<ll> dist(MAX + 5, INF);

void dijkstra(int st, int mx) {
    priority_queue<dv> pq;

    pq.push({ 0, st });
    dist[st] = 0;

    while (!pq.empty()) {
        int now = pq.top().v;
        ll d = pq.top().d;
        pq.pop();
        
        if(now==en) break;
        
        for (auto& e : adj[now]) {
            int next = e.v;
            if (e.d > mx) continue;
            if (dist[next] > d + e.d) {
	               dist[next] = d + e.d;
                pq.push({ dist[next], next });
            }
        }
    }
}

void init(){
    for(int i=1; i<=n; i++) dist[i]=INF;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    set<ll> s;
    
    cin>>n>>m>>st>>en>>c;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        s.insert(w);
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    
    vector<ll> a;
    for(auto& i : s) a.push_back(i);
    a.push_back(-1);
    
    int l=0, r=a.size()-1;
    while(l<r){
        int mid=(l+r)>>1;
        
        init();
        
        dijkstra(st, a[mid]);
        
        if(dist[en]<=c) r=mid;
        else l=mid+1;
    }
    
    cout<<a[l];
    
    return 0;
}
