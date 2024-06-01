#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, d;
    std::cin >> n >> d;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<bool> used(n, false);
    bool fail = false;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue;
        }
        int cur = i, pref = 0, last = 0, iter = 0, ans = 0;
        do {
            used[cur] = true;
            if (a[cur] == 0) {
                ans = std::max(ans, last);
                last = 0;
            } else {
                last++;
                if (iter == pref) {
                    pref++;
                }
            }
            cur = (cur + d) % n;
            iter++;
        } while (cur != i);
        if (iter != pref)
            ans = std::max(ans, pref + last);
        else {
            fail = true;
            break;
        }
        res = std::max(res, ans);
    }
    if (fail) {
        std::cout << "-1\n";
    } else {
        std::cout << res << '\n';
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
