#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "def.h"
#else
#define ck(...)
#endif
#define ll long long
#define pe(c) for (auto &e : c) cout << e << ' '; cout << '\n'
#define ps(b) cout << (b ? "YES" : "NO") << '\n'
const ll M = 1e9 + 7, N = 2e5 + 5;

bool d6(auto &s) {
    int sum = 0, n = s.size();
    int i = (s[0] == '-');
    while (i < n) sum += (s[i++] - 48);
    return (!(sum % 3) and (~(s.back() - 48) & 1));
}
void test(int tc) {
    cout << "Case " << tc << ": ";
    string s; cin >> s;
    if (d6(s)) cout << "Valid";
    else cout << "Invalid";
    cout << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios::failbit | ios::badbit);
    int tc = 0, t = 1;
    cin >> t;
    while (tc < t) test(++tc);
    return 0;
}