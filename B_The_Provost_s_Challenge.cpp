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
const ll M = 1e9 + 7, N = 1e4 + 5;

vector<int> tre[N]; int last, dmr;
void dfs(int vr, int par = 0, int dep = 0) {
    for (auto cld : tre[vr]) {
        if (cld == par) continue;
        if (dmr <= dep) {
            dmr = dep + 1; last = cld;
        }
        dfs(cld, vr, dep + 1);
    }
}

void test(int32_t tc) {
    ll n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b;
        tre[a].push_back(b); tre[b].push_back(a);
    }
    dfs(1); dmr = 0; dfs(last); cout << (dmr + 1) / 2;
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios::failbit | ios::badbit);
    int32_t tc = 0, tt = 1;
    // cin >> tt;
    while (tc++ < tt) test(tc);
    return 0;
}