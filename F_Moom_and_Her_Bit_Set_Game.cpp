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
const ll M = 1e9 + 7, N = 1e5 + 5;

ll ar[N], dp[N][35], n;
ll rec(int pos, int highBit) {
    if (pos >= n) return highBit;
    if (dp[pos][highBit] != -1) return dp[pos][highBit];
    ll ret = rec(pos + 1, highBit);
    ret = max(ret, rec(pos + 1, __builtin_popcountll(ar[pos] * highBit)));
    return dp[pos][highBit] = ret;
}

void test(int32_t tc) {
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; ++i) { cin >> ar[i]; }
    cout << rec(0, 1);
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios::failbit | ios::badbit);
    int32_t tc = 0, tt = 1;
    // cin >> tt;
    while (tc++ < tt) test(tc);
    return 0;
}