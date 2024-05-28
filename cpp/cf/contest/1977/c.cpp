#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

template <typename T1, typename T2>
inline bool relaxmi(T1 &a, const T2 &b) {
    return a > b ? a = b, true : false;
}

template <typename T1, typename T2>
inline bool relaxma(T1 &a, const T2 &b) {
    return a < b ? a = b, true : false;
}

int calc(std::vector<std::pair<int, int>> &t, int d) {
    int lcm = 0, cnt = 0;
    for (auto [j, c] : t) {
        if (d % j == 0) {
            if (lcm == 0) {
                lcm = j;
            } else {
                lcm = std::lcm(lcm, j);
            }
            cnt += c;
        }
    }
    if (lcm != d) {
        cnt = 0;
    }
    return cnt;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    ll lcm = 1;
    int mx = *std::max_element(v.begin(), v.end());
    for (auto &e : v) {
        lcm = std::lcm(lcm, e);
        if (lcm > mx) {
            std::cout << n << '\n';
            return;
        }
    }
    std::map<int, int> cnt;
    for (auto &e : v) {
        cnt[e]++;
    }
    std::vector<std::pair<int, int>> t;
    for (auto &e : cnt) {
        t.push_back(e);
    }
    int ans = 0;
    for (int i = 1; i * i <= mx; i++) {
        if (mx % i == 0) {
            if (!cnt.count(i)) {
                relaxma(ans, calc(t, i));
            }
            if (!cnt.count(mx / i)) {
                relaxma(ans, calc(t, mx / i));
            }
        }
    }
    std::cout << ans << '\n';
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
