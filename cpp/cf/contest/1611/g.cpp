#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int ans = 0;
    auto cal = [&](int num) {
        std::vector<int> v;
        for (int sum = num, ad = 0, pref = 0; sum < n + m; sum += 2, ad++) {
            std::vector<int> cur;
            int li = std::max(0, sum - m + 1), ri = std::min(n - 1, sum);
            if (li > ri) {
                continue;
            }

            for (int i = li; i <= ri; i++) {
                int j = sum - i;

                if (a[i][j] == '1') {
                    cur.emplace_back(i);
                }
            }

            while (pref != v.size() && v[pref] + ad > ri) {
                pref++;
            }
            for (int i = pref; i < v.size(); i++) {
                int new_val = v[i];
                while (!cur.empty() && cur.back() - ad >= v[i]) {
                    new_val = std::max(new_val, cur.back() - ad);
                    cur.pop_back();
                }
                v[i] = new_val;
            }
            if (!cur.empty()) {
                v.emplace_back(cur.back() - ad);
                ans++;
            }
        }
    };
    cal(0);
    cal(1);
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
