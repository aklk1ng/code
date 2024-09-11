#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 200200;
const int M = 200200;

int n, m, k, w, p;
ll arr[N], prr[M];

static inline ll calcc(int i, int j) {
    int upr = std::min(i, n - k);
    int leftr = std::min(j, m - k);
    int upl = std::max(-1LL, (ll)i - k);
    int leftl = std::max(-1LL, (ll)j - k);
    return (upr - upl) * (leftr - leftl);
}

void build() {
    std::sort(arr, arr + w);
    std::reverse(arr, arr + w);
    p = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            prr[p++] = calcc(i, j);
        }
    }
    std::sort(prr, prr + p);
    std::reverse(prr, prr + p);
}

void solve() {
    std::cin >> n >> m >> k >> w;
    for (int i = 0; i < w; ++i) {
        std::cin >> arr[i];
    }
    build();

    ll sum = 0;
    for (int i = 0; i < w; ++i) {
        sum += prr[i] * arr[i];
    }
    std::cout << sum << '\n';
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
