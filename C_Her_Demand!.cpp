#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "def.h"
#else
#define ck(...)
#endif
#define ll long long
#define pe(c) for (auto e : c) cout << e << ' '; cout << '\n'
#define ps(b) cout << (b ? "Yes" : "No") << '\n'
const ll M = 1e9 + 7, N = 2e5 + 5;

string pat;
auto kmp(auto &str) {
    int pl = pat.size(), sl = str.size(), sz = max(pl, sl) + 5, pi[sz], now = pi[0] = -1;
    for (int i = 1; i < pl; ++i) {
        while (now != -1 && pat[now + 1] != pat[i]) now = pi[now];
        if (pat[now + 1] == pat[i]) ++now; pi[i] = now;
    }
    int match = 0; now = -1; vector<int> ind;
    for (int i = 0; i < sl; ++i) {
        while (now != -1 && pat[now + 1] != str[i]) now = pi[now];
        if (pat[now + 1] == str[i]) ++now;
        if(now == pl - 1) ind.emplace_back(i - pl + 1);
    }
    return ind;
}
void test(int tc) {
    cout << "Case " << tc << ": ";
    ll n, m, c; cin >> n >> m >> c;
    ll ar[m]; for (int i = 0; i < m; ++i) cin >> ar[i];
    cin >> pat; transform(pat.begin(), pat.end(), pat.begin(), ::tolower);
    bool ok = 0;
    while (n--) {
        ll tot = 0;
        string s; cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        auto v = kmp(s);
        for (auto e : v) {
            if (tot < c) tot += ar[e];
            else break;
        }
        if (tot >= c) ok = 1;
    }
    ps(ok);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios::failbit | ios::badbit);
    int32_t tc = 0, tt = 1;
    cin >> tt;
    while (tc++ < tt) test(tc);
    return 0;
}