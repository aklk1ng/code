#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

std::map<std::string, bool> vis;
std::map<std::string, std::tuple<int, int, int>> pos;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<bool> dp(m + 1);
    std::vector<int> p(m + 1);
    std::vector<std::string> cache;
    dp[0] = true;

    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;

        for (int j = 0; j < m; j++) {
            std::string t;
            t += s[j];

            for (int k = 1; k <= 2; k++) {
                if (k + j >= m) {
                    break;
                }
                t += s[j + k];
                if (!vis[t]) {
                    vis[t] = true;
                    pos[t] = {j, j + k, i};
                    cache.push_back(t);
                }
            }
        }
    }
    std::string s;
    std::cin >> s;
    for (int i = 0; i < m; i++) {
        std::string t;
        t += s[i];

        for (int k = 1; k <= 2; k++) {
            if (i - k < 0) {
                break;
            }
            t = s[i - k] + t;
            if (vis[t] && dp[i - k]) {
                dp[i + 1] = true;
                p[i + 1] = i - k;
            }
            if (dp[i + 1]) {
                break;
            }
        }
    }
    for (auto &e : cache) {
        vis[e] = false;
    }
    if (!dp[m]) {
        std::cout << "-1\n";
        return;
    }
    std::vector<std::tuple<int, int, int>> ans;
    for (int k = m; k > 0;) {
        int t = p[k];
        auto tmp = s.substr(t, k - t);
        ans.emplace_back(pos[tmp]);
        k = t;
    }
    std::cout << ans.size() << '\n';
    std::reverse(ans.begin(), ans.end());
    for (auto &[l, r, i] : ans) {
        std::cout << l + 1 << ' ' << r + 1 << ' ' << i + 1 << '\n';
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
