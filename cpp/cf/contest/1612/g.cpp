#include <bits/stdc++.h>
using ll = long long;
const int mod = 1e9 + 7;

template <class A, class B>
std::ostream &operator<<(std::ostream &out, const std::pair<A, B> &p) {
    return out << "(" << p.x << " " << p.y << ")";
}

template <class A>
std::ostream &operator<<(std::ostream &out, const std::vector<A> &v) {
    for (int i = 0; i < v.size(); i++) {
        if (i) {
            out << " ";
        }
        out << v[i];
    }
    return out;
}

int norm(int a) {
    while (a >= mod) {
        a -= mod;
    }
    while (a < 0) {
        a += mod;
    }
    return a;
}

int mul(int a, int b) { return int(a * 1ll * b % mod); }

const int MX = int(1e6) + 55;
int n;
ll total;
int cnt[MX];

inline bool read() {
    if (!(std::cin >> n)) {
        return false;
    }
    total = 0;
    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        cnt[k]++;
        total += k;
    }
    return true;
}

int fact[MX];

void solve() {
    fact[0] = 1;
    for (int i = 1; i < MX; i++) {
        fact[i] = mul(fact[i - 1], i);
    }

    int ansSum = 0;
    int ansCnt = 1;

    for (int lvl = MX - 1; lvl > 1; lvl--) {
        ansCnt = mul(ansCnt, mul(fact[cnt[lvl]], fact[cnt[lvl]]));

        ansSum = norm(ansSum +
                      mul(mul(lvl - 1, cnt[lvl]), (total - cnt[lvl]) % mod));

        total -= 2 * cnt[lvl];
        cnt[lvl - 2] += cnt[lvl];
    }

    ansCnt = mul(ansCnt, fact[cnt[1]]);

    std::cout << ansSum << " " << ansCnt << '\n';
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
        read();
        solve();
    }

    return 0;
}
