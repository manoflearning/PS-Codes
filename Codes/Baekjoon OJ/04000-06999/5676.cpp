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

const int MAXN = 1e5;  // limit for array size

struct Seg {
    int N;  // array size
    int t[2 * MAXN];

    void build(int n) {
        N = n;
        for (int i = 0; i < N; i++) {
            int x; cin >> x;
            if (x > 0) t[N + i] = 1;
            else if (x < 0) t[N + i] = -1;
            else t[N + i] = 0;
        }
        for (int i = N - 1; i >= 1; i--) t[i] = t[i << 1] * t[i << 1 | 1];
    }
    void modify(int p, int val) {  // set value at position p
        if (val > 0) val = 1;
        else if (val < 0) val = -1;
        
        for (t[p += N] = val; p > 1; p >>= 1) t[p >> 1] = t[p] * t[p ^ 1];
    }
    int query(int l, int r) {  // sum on interval [l, r)
        int ret = 1;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ret *= t[l++];
            if (r & 1) ret *= t[--r];
        }
        return ret;
    }
}seg;

int n, k;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    while (1) {
        cin >> n >> k;
        
        if (cin.eof()) break;
        
        seg.build(n);
    
        for (int i = 0; i < k; i++) {
            char q; int a, b;
            cin >> q >> a >> b;
        
            if (q == 'C') seg.modify(a - 1, b);
            else {
                int res = seg.query(a - 1, b);
                if (res == 1) cout << '+';
                else if (res == 0) cout << '0';
                else cout << '-';
            }
        }
        
        cout << '\n';
    }
    
    return 0;
}
