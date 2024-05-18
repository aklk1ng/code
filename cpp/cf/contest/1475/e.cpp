#include <bits/stdc++.h>
using ll = long long;
const int mod = 1e9 + 7;

int pow(int a, int p) {
    int res = 1;
    while (p) {
        if (p % 2 == 0) {
            a = a * 1ll * a % mod;
            p /= 2;
        } else {
            res = res * 1ll * a % mod;
            p--;
        }
    }
    return res;
}

int fact(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res = res * 1ll * i % mod;
    }
    return res;
}

int C(int n, int k) {
    return fact(n) * 1ll * pow(fact(k), mod - 2) % mod * 1ll *
           pow(fact(n - k), mod - 2) % mod;
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        cnt[x]++;
    }

    for (int i = n; i >= 0; i--){
        if (cnt[i] >= k) {
            std::cout << C(cnt[i], k) << '\n';
            return;
        } else {
            k -= cnt[i];
        }
    }
    std::cout << 1 << '\n';
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
