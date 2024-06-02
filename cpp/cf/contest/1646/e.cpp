#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int M = 1000006;

const int N = 20;

bool vis[M * N];

void solve() {
    ll n, m;
    std::cin >> n >> m;
    std::vector<ll> mul(N);
    ll cur = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (!vis[i * j]) {
                vis[i * j] = 1;
                cur++;
            }
        }
        mul[i] = cur;
    }
    ll res = 1;
    std::vector<ll> t(n + 1);
    for (int i = 2; i < n + 1; i++) {
        if (t[i]) {
            continue;
        }
        ll power = i, power_quan = 0;
        while (power <= n) {
            t[power] = 1;
            power_quan++;
            power *= i;
        }
        res += mul[power_quan];
    }
    std::cout << res << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    if (false) {
        std::cin >> T;
    }
    while (T--) {
        solve();
    }

    return 0;
}
