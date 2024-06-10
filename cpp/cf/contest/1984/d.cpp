#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

std::vector<int> z_function(std::string s) {
    int n = s.size();
    std::vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i < r) {
            z[i] = std::min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] > r) {
            l = i, r = i + z[i];
        }
    }
    return z;
}

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.length();

    std::vector<int> nona(n, n);
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] != 'a') {
            nona[i] = i;
        } else if (i + 1 < n) {
            nona[i] = nona[i + 1];
        }
    }
    if (nona[0] == n) {
        std::cout << n - 1 << '\n';
        return;
    }
    std::string s2 = "";
    int i1 = nona[0];
    for (int i = i1; i < n; ++i) {
        s2 += s[i];
    }
    std::vector<int> z = z_function(s2);
    ll ans = 0;
    for (int len = 1; i1 + len <= n; ++len) {
        int cur = i1 + len;
        int mn = i1;
        bool ok = true;
        while (cur < n) {
            if (nona[cur] == n) {
                break;
            }
            int bt = nona[cur] - cur;
            mn = std::min(mn, bt);
            cur += bt;
            if (z[cur - i1] < len) {
                ok = false;
                break;
            }
            cur += len;
        }
        if (ok) {
            ans += mn + 1;
        }
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
