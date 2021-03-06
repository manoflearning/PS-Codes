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
const int MAX = 1e5;

vector<int> cnt(MAX + 1);
set<int> s2, s4, s6, s8;

void f(int i) {
    if (cnt[i] >= 2) s2.insert(i);
    if (cnt[i] >= 4) {
        s2.erase(i);
        s4.insert(i);
    }
    if (cnt[i] >= 6) {
        s4.erase(i);
        s6.insert(i);
    }
    if (cnt[i] >= 8) {
        s6.erase(i);
        s8.insert(i);
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;

    vector<int> a(n);
    for (int& i : a) {
        cin >> i;
        cnt[i]++;
    }

    for (int i = 1; i <= MAX; i++) f(i);

    int q; cin >> q;
    while (q--) {
        char op; int i;
        cin >> op >> i;

        if (op == '+') {
            cnt[i]++;
            f(i);
        }
        else {
            cnt[i]--;
            if (cnt[i] < 2) s2.erase(i);
            if (cnt[i] < 4) s4.erase(i);
            if (cnt[i] < 6) s6.erase(i);
            if (cnt[i] < 8) s8.erase(i);
            f(i);
        }
        //cout << s2.size() << ' ' << s4.size() << ' ' << s6.size() << ' ' << s8.size() << '\n';
        if (s8.size()) cout << "YES\n";
        else if (s6.size() >= 2 || (s6.size() == 1 && (s2.size() || s4.size()))) cout << "YES\n";
        else if (s4.size() >= 2 || (s4.size() == 1 && s2.size() >= 2)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}