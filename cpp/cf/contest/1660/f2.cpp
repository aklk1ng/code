#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    std::vector<int> f(3);
    int cur = n;
    std::vector<int> v(2 * n + 1);
    v[cur]++;
    f[cur % 3]++;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int tmp = cur;
        if (s[i] == '-') {
            tmp--;
            f[tmp % 3] += v[tmp];
            ans += f[tmp % 3];
            v[tmp]++;
            f[tmp % 3]++;
        } else {
            f[tmp % 3] -= v[tmp];
            tmp++;
            ans += f[tmp % 3];
            v[tmp]++;
            f[tmp % 3]++;
        }
        cur = tmp;
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    if (true) {
        std::cin >> T;
    }
    while (T--) {
        solve();
    }

    return 0;
}
