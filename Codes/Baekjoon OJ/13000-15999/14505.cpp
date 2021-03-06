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
const int MAX = 1e3;

string S;
int dp[MAX+5][MAX+5];

int f(int s, int e) {
    int& ret=dp[s][e];
    if(ret!=-1) return ret;
    if(s==e) return ret=1;
    
    ret=0;
    for(int i=s; i<=e; i++){
        for(int j=i; j<=e; j++){
            if(S[i]==S[j]){
                ret+=f(i+1, j-1)+1;
            }
        }
    }
    return ret;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(dp, -1, sizeof(dp));
    
    cin>>S;
    
    cout<<f(0, S.size()-1);
    
    return 0;
}
