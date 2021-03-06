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

struct Q {
    int l, r, k;
};

struct LR {
    int l, r;
};

struct LRidx {
    int l, r, idx;
};

int n, m;
vector<Q> q1, q2;
set<int> s;
vector<LR> lr;
map<int, int> mp;
vector<LRidx> is2[50005];
vector<ll> psum, ans;

struct Seg {
    int flag;  // array size
    vector<ll> t, lazy;

    void build() {
        for (flag = 1; flag < n; flag <<= 1);
        t.resize(2 * flag);
        lazy.resize(2 * flag);
    }
    void modify(int l, int r, int value) {
        return modify(l, r, 1, 0, flag - 1, value);
    }
    // add a value to all elements in interval [l, r]
    void modify(int l, int r, int n, int nl, int nr, int value) {
        propagate(n, nl, nr);

        if (r < nl || nr < l) return;
        if (l <= nl && nr <= r) {
            lazy[n] += value;
            propagate(n, nl, nr);
            return;
        }

        int mid = (nl + nr) >> 1;
        modify(l, r, n << 1, nl, mid, value);
        modify(l, r, n << 1 | 1, mid + 1, nr, value);

        t[n] = t[n << 1] + t[n << 1 | 1];
    }
    ll query(int l, int r) {
        return query(l, r, 1, 0, flag - 1);
    }
    ll query(int l, int r, int n, int nl, int nr) {  // sum on interval [l, r]
        propagate(n, nl, nr);

        if (r < nl || nr < l) return 0;
        if (l <= nl && nr <= r) return t[n];

        int mid = (nl + nr) / 2;
        return query(l, r, n << 1, nl, mid) + query(l, r, n << 1 | 1, mid + 1, nr);
    }
    void propagate(int n, int nl, int nr) {
        if (lazy[n] != 0) {
            if (n < flag) {
                lazy[n << 1] += lazy[n];
                lazy[n << 1 | 1] += lazy[n];
            }
            ll w = psum[nr] - (nl == 0 ? 0 : psum[nl - 1]);
            t[n] += lazy[n] * w;
            lazy[n] = 0;
        }
    }
}seg;

void input() {
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, l, r, k;
        cin >> a >> l >> r >> k;
        s.insert(l);
        s.insert(r);
        if (a == 1) q1.push_back({l, r, k});
        if (a == 2) {
            q2.push_back({l, r, k - 1});
            is2[k - 1].push_back({l, r, q2.size() - 1});
        }
    }
    
    ans.resize(q2.size());
}

void setInterval() {
    int l = 1;
    for (auto& i : s) {
        if (lr.empty() || i > lr.back().r + 1) {
            lr.push_back({l, i - 1});
        }
        lr.push_back({i, i});
        mp.insert({i, lr.size() - 1});
        l = i + 1;
    }
    
    n = lr.size();
}

void makePsum() {
    psum.resize(n);
    
    psum[0] = lr[0].r - lr[0].l + 1;
    for (int i = 1; i < n; i++) {
        int w = lr[i].r - lr[i].l + 1;
        psum[i] = w + psum[i - 1];
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    input();
    
    setInterval();
    
    makePsum();
    
    seg.build();
    
    for (int i = 0; i < q1.size(); i++) {
        int l = q1[i].l, r = q1[i].r, k = q1[i].k;
        
        seg.modify(mp[l], mp[r], k);
        
        for (auto& j : is2[i])
            ans[j.idx] = seg.query(mp[j.l], mp[j.r]);
    }
    
    for (auto& i : ans) 
        cout << i << '\n';
    
    return 0;
}
