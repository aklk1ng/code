#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 1e6 + 1;
bool used[N];
bool divs[N];

void solve() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> a(n);
    std::vector<int> vecDivs;
    for (int d = 1; d * d <= x; d++) {
        if (x % d == 0) {
            divs[d] = true;
            vecDivs.push_back(d);
            if (d * d < x) {
                vecDivs.push_back(x / d);
                divs[x / d] = true;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int ans = 1;
    used[1] = true;
    std::vector<int> cur{1};
    for (int i = 0; i < n; i++) {
        if (!divs[a[i]]) {
            continue;
        }
        std::vector<int> ncur;
        bool ok = true;
        for (int d : cur)
            if (1ll * d * a[i] <= x && divs[d * a[i]] && !used[d * a[i]]) {
                ncur.push_back(d * a[i]);
                used[d * a[i]] = true;
                if (d * a[i] == x) {
                    ok = false;
                }
            }
        for (int d : ncur) {
            cur.push_back(d);
        }
        if (!ok) {
            ans++;
            for (int d : cur) {
                used[d] = false;
            }
            used[1] = true;
            used[a[i]] = true;
            cur = std::vector<int>{1, a[i]};
        }
    }
    for (int d : vecDivs) {
        divs[d] = false;
        used[d] = false;
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (true) {
        std::cin >> _;
    }
    while (_--) {
        solve();
    }

    return 0;
}
