#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 998244353;

int N, M;
ll dp[1005][105][3];

ll cal_begin();
ll cal(int n, int m, int dir);

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    //reset
    for (int i = 0; i < 1005; i++) {
        for (int l = 0; l < 105; l++) {
            for (int j = 0; j < 3; j++) {
                dp[i][l][j] = -1;
            }
        }
    }

    //����
    cin >> N >> M;

    ll sum = cal_begin();

    cout << sum;

    return 0;
}

ll cal_begin() {
    ll ret = 0;

    for (int i = 1; i <= M; i++) {
        ret += cal(2, i, 0);
        ret %= MOD;
    }

    return ret;
}

ll cal(int n, int m, int dir) {
    ll& ret = dp[n][m][dir];
    //memoization, base case
    if (ret != -1) return ret;
    if (n == N + 1) return ret = 1;

    ret = 0;

    if (dir == 0 || dir == 1) {
        for (int i = 1; i < m; i++) {
            ret += cal(n + 1, i, 1);
            ret %= MOD;
        }
        ret += cal(n + 1, m, 0);
        ret %= MOD;
        for (int i = m + 1; i <= M; i++) {
            ret += cal(n + 1, i, 2);
            ret %= MOD;
        }
    }
    else if (dir == 2) {
        ret += cal(n + 1, m, 0);
        ret %= MOD;
        for (int i = m + 1; i <= M; i++) {
            ret += cal(n + 1, i, 2);
            ret %= MOD;
        }
    }

    return ret;
}