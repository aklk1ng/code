#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::string s, t;
    std::cin >> n >> s >> t;

    auto get_range = [&](int i) {
        if (s[i] == '1') {
            return std::make_pair(i, i);
        }
        int l = -1, r = -1;
        if (i > 0 && t[i - 1] == '1') {
            l = i - 1;
        } else if (i > 1 && t[i - 1] == '0' && s[i - 2] == '0') {
            l = i - 2;
        }
        if (i + 1 < n && t[i + 1] == '1') {
            r = i + 1;
        } else if (i + 2 < n && t[i + 1] == '0' && s[i + 2] == '0') {
            r = i + 2;
        }
        if (l == -1) {
            r = -1;
        }
        if (r == -1) {
            l = -1;
        }
        return std::make_pair(l, r);
    };

    std::vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + (get_range(i).first != -1);
    }

    int q;
    std::cin >> q;
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        int ans = 0;
        if (r - l <= 5) {
            for (int i = l - 1; i < r; i++) {
                auto [ll, rr] = get_range(i);
                if (ll >= l - 1 && rr < r) {
                    ans++;
                }
            }
        } else {
            ans = pref[r] - pref[l - 1];
            for (int j : {l - 1, l, r - 2, r - 1}) {
                auto [ll, rr] = get_range(j);
                if (ll != -1 && (ll < l - 1 || rr >= r)) {
                    ans--;
                }
            }
        }
        std::cout << ans << '\n';
    }
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
