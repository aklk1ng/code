#include <bits/stdc++.h>
using ll = long long;
const int mod = 1e9 + 7;

struct mod_int {
    int val;

    mod_int(long long v = 0) {
        if (v < 0) {
            v = v % mod + mod;
        }

        if (v >= mod) {
            v %= mod;
        }

        val = v;
    }

    static int mod_inv(int a, int m = mod) {
        int g = m, r = a, x = 0, y = 1;

        while (r != 0) {
            int q = g / r;
            g %= r;
            std::swap(g, r);
            x -= q * y;
            std::swap(x, y);
        }

        return x < 0 ? x + m : x;
    }

    explicit operator int() const { return val; }

    mod_int &operator+=(const mod_int &other) {
        val += other.val;
        if (val >= mod) {
            val -= mod;
        }
        return *this;
    }

    mod_int &operator-=(const mod_int &other) {
        val -= other.val;
        if (val < 0) {
            val += mod;
        }
        return *this;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = mod) {
#if !defined(_WIN32) || defined(_WIN64)
        return x % m;
#endif
        unsigned x_high = x >> 32, x_low = (unsigned)x;
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a"(quot), "=d"(rem)
            : "d"(x_high), "a"(x_low), "r"(m));
        return rem;
    }

    mod_int &operator*=(const mod_int &other) {
        val = fast_mod((uint64_t)val * other.val);
        return *this;
    }

    mod_int &operator/=(const mod_int &other) { return *this *= other.inv(); }

    friend mod_int operator+(const mod_int &a, const mod_int &b) {
        return mod_int(a) += b;
    }

    friend mod_int operator-(const mod_int &a, const mod_int &b) {
        return mod_int(a) -= b;
    }

    friend mod_int operator*(const mod_int &a, const mod_int &b) {
        return mod_int(a) *= b;
    }

    friend mod_int operator/(const mod_int &a, const mod_int &b) {
        return mod_int(a) /= b;
    }

    mod_int &operator++() {
        val = val == mod - 1 ? 0 : val + 1;
        return *this;
    }

    mod_int &operator--() {
        val = val == 0 ? mod - 1 : val - 1;
        return *this;
    }

    mod_int operator++(int32_t) {
        mod_int before = *this;
        ++*this;
        return before;
    }

    mod_int operator--(int32_t) {
        mod_int before = *this;
        --*this;
        return before;
    }

    mod_int operator-() const { return val == 0 ? 0 : mod - val; }

    bool operator==(const mod_int &other) const { return val == other.val; }

    bool operator!=(const mod_int &other) const { return val != other.val; }

    mod_int inv() const { return mod_inv(val); }

    mod_int pow(long long p) const {
        assert(p >= 0);
        mod_int a = *this, result = 1;

        while (p > 0) {
            if (p & 1) {
                result *= a;
            }

            a *= a;
            p >>= 1;
        }

        return result;
    }

    friend std::ostream &operator<<(std::ostream &stream, const mod_int &m) {
        return stream << m.val;
    }

    friend std::istream &operator>>(std::istream &stream, mod_int &m) {
        return stream >> m.val;
    }
};

const int N = 5e6 + 5;
mod_int fact[N], inv[N], invv[N];

void init(int n = N) {
    fact[0] = inv[0] = inv[1] = 1;
    invv[0] = invv[1] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = i * fact[i - 1];
    }
    for (int i = 2; i < N; i++) {
        invv[i] = (mod - mod / i) * invv[mod % i];
        inv[i] = invv[i] * inv[i - 1];
    }
}

mod_int C(int n, int r) {
    if (r > n || r < 0) {
        return 0;
    }
    return fact[n] * inv[n - r] * inv[r];
}

void solve() {

    int n, m;
    std::cin >> n >> m;
    if (m > n) {
        std::swap(n, m);
    }
    auto brute = [&]() {
        std::vector<std::vector<mod_int>> dp(n + 1,
                                             std::vector<mod_int>(m + 1));
        std::vector<std::vector<mod_int>> exp(n + 1,
                                              std::vector<mod_int>(m + 1));
        dp[0][0] = 1;
        exp[0][0] = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i + j == 0) {
                    continue;
                }
                for (int x = 0; x <= i; x++) {
                    for (int y = 0; y <= j; y++) {
                        if (x + y == i + j) {
                            continue;
                        }
                        dp[i][j] += dp[x][y];
                        exp[i][j] += (exp[x][y] + dp[x][y]);
                    }
                }
            }
        }
        return exp[n][m] + dp[n][m];
    };
    auto correct = [&]() {
        mod_int in = mod_int(2).inv();
        auto d = [&](int x) {
            mod_int val = x + 1;
            return val * in;
        };
        mod_int ans = 0;
        mod_int pw = mod_int(2).pow(n + m);
        for (int i = 0; i <= m; i++) {
            pw *= in;
            ans += C(n, i) * C(m, i) * pw * (i + d(n + m - i) + 1);
        }
        return ans;
    };
    std::cout << correct() << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    init();
    if (true) {
        std::cin >> T;
    }
    while (T--) {
        solve();
    }

    return 0;
}
