#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 2e5 + 5;

std::vector<int> a(N), psum(N);

int f(int x) {
    int res = 0;
    while (x) {
        x /= 3;
        res++;
    }
    return res;
}

void init() {
    psum[0] = 0;
    for (int i = 1; i < N - 1; i++) {
        a[i] = f(i);
        psum[i] = psum[i - 1] + a[i];
    }
}

void solve() {
    int l, r;
    std::cin >> l >> r;

    std::cout << psum[r] - psum[l - 1] + a[l] << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (true) {
        std::cin >> _;
    }
    init();
    while (_--) {
        solve();
    }

    return 0;
}
