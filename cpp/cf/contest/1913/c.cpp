#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int m;
    std::cin >> m;
    const int N = 30;
    std::vector<int> cnt(N);
    std::vector<std::string> ans;
    while (m--) {
        int t, v;
        std::cin >> t >> v;
        if (t == 1) {
            cnt[v]++;
        } else {
            int nw = 0;
            bool ok = true;
            for (int i = 0; i < N; i++) {
                int r = (v % (2 << i)) / (1 << i);
                if (r > nw + cnt[i]) {
                    ans.push_back("NO");
                    ok = false;
                    break;
                }
                v -= r;
                nw = (nw + cnt[i] - r) / 2;
            }
            if (ok) {
                ans.push_back(nw >= (v >> 30) ? "YES" : "NO");
            }
        }
    }
   for (const auto& res : ans) {
        std::cout << res << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    if (false) {
        std::cin >> T;
    }
    while (T--) {
        solve();
    }

    return 0;
}
