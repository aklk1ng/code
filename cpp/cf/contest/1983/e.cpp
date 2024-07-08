#include <bits/stdc++.h>
using ll = long long;
const int mod = 1e9 + 7;

ll power(ll a, ll b) {
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

ll inline inv(ll x) { return power(x, mod - 2); }

void solve() {
    ll n, k;
    std::cin >> n >> k;
    std::vector<int> v(n);
    ll spe_value = 0, nor_value = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
        if (i < k) {
            spe_value += v[i];
        } else {
            nor_value += v[i];
        }
    }

    int tot = (nor_value + spe_value) % mod;
    nor_value %= mod;
    spe_value %= mod;
    spe_value = (spe_value * inv(k)) % mod;
    nor_value = (nor_value * inv(n - k)) % mod;
    int cnt = (n - k + 1) / 2;
    ll expected_special_balls =
        (((((n - k + 2) / 2) * k) % mod) * inv(n - k + 1)) % mod;
    ll expected_alice_score =
        (cnt * nor_value + expected_special_balls * spe_value) % mod;
    ll expected_bob_score = ((tot - expected_alice_score) % mod + mod) % mod;
    std::cout << expected_alice_score << " " << expected_bob_score << "\n";
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
