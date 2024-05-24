#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void answer(int x) {
    std::cout << "! " << x << '\n';
    std::cout.flush();
    std::cin >> x;
}

void solve() {
    int n, k;
    std::cin >> n >> k;

    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        std::cout << "? 1 " << i * n << '\n';
        std::cout.flush();
        int x;
        std::cin >> x;
        if (x == n) {
            mx = i;
            break;
        }
    }
    for (int c = mx * (n / k);; c -= mx) {
        if (!c) {
            answer(-1);
            return;
        }
        int l = 0;
        int bad = 0;
        for (int _ = 0; _ < k; _++) {
            if (l >= n) {
                bad = 1;
                break;
            }
            std::cout << "? " << l + 1 << ' ' << c << '\n';
            std::cout.flush();
            int x;
            std::cin >> x;
            l = x;
        }
        if (bad) {
            continue;
        }
        if (l != n) {
            continue;
        }
        answer(c);
        return;
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
