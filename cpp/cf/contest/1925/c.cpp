#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, k, m;
    std::cin >> n >> k >> m;
    std::string s;
    std::cin >> s;

    std::string ans;
    std::vector<bool> vis(k);
    int cnt = 0;
    for (char &c : s) {
        if (ans.size() == n) {
            break;
        }
        cnt += !vis[c - 'a'];
        vis[c - 'a'] = true;
        if (cnt == k) {
            vis.assign(k, false);
            cnt = 0;
            ans += c;
        }
    }
    if (ans.size() == n) {
        std::cout << "YES\n";
        return;
    }
    std::cout << "NO\n";
    for (int i = 0; i < k; i++) {
        if (!vis[i]) {
            while (ans.size() < n) {
                ans += char('a' + i);
            }
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
