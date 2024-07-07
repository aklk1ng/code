#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m;
    std::cin >> n >> m;
    int mx = 0, mi = INT_MAX;
    std::vector<int> appear(m + 1), toggle(m + 1), mxval(m + 1);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        appear[x] = 1;
        toggle[x] = 1;
        mi = std::min(mi, x);
        mx = std::max(mx, x);
    }

    for (int i = 0; i <= mx; i++) {
        mxval[i] = i;
    }
    int ptr = mx, smx = mx - mi;
    for (int i = mx; i >= 1; i--) {
        for (ll j = (ll)i * i; j <= mx; j += i) {
            if (appear[j]) {
                toggle[mxval[j]]--;
            }
            mxval[j] = std::min(mxval[j], mxval[j / i]);
            if (appear[j]) {
                toggle[mxval[j]]++;
            }
        }
        while (!toggle[ptr]) {
            ptr--;
        }
        if (i <= mi) {
            smx = std::min(smx, ptr - i);
        }
    }
    std::cout << smx << '\n';
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
