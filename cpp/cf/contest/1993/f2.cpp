#include <bits/stdc++.h>
using ll = long long;
const int N = 1e6 + 5;

std::vector<int> primes;
bool is_composite[2 * N];
int phi[2 * N];
std::string s;

ll mypow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll inv(ll a, ll mod) { return mypow(a, phi[mod] - 1, mod); }

void init() {
    for (int i = 2; i < 2 * N; i++) {
        if (!is_composite[i]) {
            phi[i] = i - 1;
            primes.push_back(i);
        }
        for (int j : primes) {
            if (i * j >= 2 * N) {
                break;
            }
            is_composite[i * j] = true;
            if (i % j == 0) {
                phi[i * j] = phi[i] * j;
                break;
            } else {
                phi[i * j] = phi[i] * (j - 1);
            }
        }
    }
}

ll solve_mod(int a, int b, int M) {
    int g = std::gcd(a, M);
    if (b % g) {
        return -1;
    }

    a /= g;
    b /= g;
    M /= g;
    if (M == 1) {
        return 0;
    }
    return ((ll)b * inv(a, M)) % M;
}

void solve() {
    ll n, K, W, H;
    std::cin >> n >> K >> W >> H >> s;
    K--;

    std::vector<std::pair<ll, ll>> p;
    ll xn = 0, yn = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            xn--;
        }
        if (s[i] == 'R') {
            xn++;
        }
        if (s[i] == 'D') {
            yn--;
        }
        if (s[i] == 'U') {
            yn++;
        }
        xn = (xn + 2 * W) % (2 * W);
        yn = (yn + 2 * H) % (2 * H);
        p.emplace_back(xn, yn);
    }

    ll WW = 2 * W / std::gcd(2 * W, xn);
    ll HH = 2 * H / std::gcd(2 * H, yn);
    ll ans = 0, L = std::lcm(HH, WW);
    for (auto [xt, yt] : p) {
        if (xt) {
            xt = 2 * W - xt;
        }
        if (yt) {
            yt = 2 * H - yt;
        }

        auto kx = solve_mod(xn, xt, 2 * W);
        auto ky = solve_mod(yn, yt, 2 * H);
        if (kx == -1 || ky == -1) {
            continue;
        }

        ll rem = (ky - kx) % HH;
        if (rem < 0) {
            rem += HH;
        }

        int kk = solve_mod(WW, rem, HH);
        if (kk == -1) {
            continue;
        }

        ll a = kk * WW + kx;
        if (a <= K) {
            ans += (K - a) / L + 1;
        }
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
    init();
    while (_--) {
        solve();
    }

    return 0;
}
