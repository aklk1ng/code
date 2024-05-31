#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

int n;

std::map<std::pair<int, int>, int> cache;

void dec(int pos, int L, int R) {
    cache[{L, R}]--;

    if (L != R) {
        int M = (L + R) / 2;
        if (pos <= M) {
            dec(pos, L, M);
        } else {
            dec(pos, M + 1, R);
        }
    }
}

void solve() {
    int k;
    std::cin >> k;

    int l = 0, r = n - 1;
    while (l != r) {
        int m = (l + r) / 2;
        std::pair<int, int> t = {l, m};
        if (cache.count(t) == 0) {
            std::cout << "? " << t.first + 1 << " " << t.second + 1
                      << std::endl;
            std::cin >> cache[t];
            cache[t] = t.second - t.first + 1 - cache[t];
        }
        int val = cache[t];
        if (k <= val) {
            r = m;
        } else {
            k -= val;
            l = m + 1;
        }
    }
    std::cout << "! " << l + 1 << std::endl;
    dec(l, 0, n - 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n;
    int T = 1;
    if (true) {
        std::cin >> T;
    }
    while (T--) {
        solve();
    }

    return 0;
}
