#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "def.h"
#else
#define ck(...)
#endif
#define ll long long
#define pe(c) for (auto e : c) cout << e << ' '; cout << '\n'
#define ps(b) cout << (b ? "YES" : "NO") << '\n'
const ll M = 1e9 + 7, N = 2e5 + 5;

auto sseq(auto &inp) {
    int sz = inp.size(), n = (1 << sz); vector<vector<ll>> res;
    for (int i = 1; i < n; ++i) {
        vector<ll> sub; int j = 0, hi = __builtin_popcount(i);
        while (hi) {
            if (i & (1 << j)) { sub.push_back(inp[j]); --hi; } ++j;
        }
        res.push_back(sub);
    }
    return res;
}
void test(int32_t tc) {
    ll n; cin >> n;
    vector<ll> ar(n); for (int i = 0; i < n; ++i) { cin >> ar[i]; }
    auto sub = sseq(ar);
    ll res = 0;
    for (auto r : sub) {
        ll xr = 0;
        for (auto e : r) xr ^= e;
        res = max(res, xr);
    }
    cout << res;
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios::failbit | ios::badbit);
    int32_t tc = 0, tt = 1;
    // cin >> tt;
    while (tc++ < tt) test(tc);
    return 0;
}