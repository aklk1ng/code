#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int x;
        std::cin >> x;
        a[--x]++;
    }

    auto proc = [&](auto self) {
        if (a.empty()) {
            return;
        }
        int n = a.size();
        int last = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == a[0]) {
                last = i;
            } else {
                break;
            }
        }
        --a[last];
        for (int i = 0; i < n; ++i) {
            --a[i];
        }
        ++ans;
        while (!a.empty() && a.back() <= 0) {
            a.pop_back();
        }
        self(self);
    };
    a.emplace_back(1);
    std::sort(a.rbegin(), a.rend());
    while (!a.empty() && a.back() <= 0) {
        a.pop_back();
    }
    n = a.size();
    for (int i = 0; i < n; i++) {
        a[i] = a[i] - (n - i);
        ans++;
    }
    std::sort(a.rbegin(), a.rend());
    while (!a.empty() && a.back() <= 0) {
        a.pop_back();
    }
    proc(proc);
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
