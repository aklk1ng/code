#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

struct desk {
    bool t[2][2]{};

    desk() = default;

    desk(bool t11, bool t01, bool t10, bool t00) : t{{t00, t01}, {t10, t11}} {}
};

desk operator*(const desk &a, const desk &b) {
    desk c{a.t[1][1] && b.t[1][1] || a.t[1][0] && b.t[0][1],
           a.t[0][1] && b.t[1][1] || a.t[0][0] && b.t[0][1],
           a.t[1][1] && b.t[1][0] || a.t[1][0] && b.t[0][0],
           a.t[0][0] && b.t[0][0] || a.t[0][1] && b.t[1][0]};
    return c;
}

constexpr int shift = 1 << 17;
desk sg[shift << 1];

void sg_set(int index, const desk &d) {
    index += shift;
    sg[index] = d;
    do {
        index >>= 1;
        sg[index] = sg[index * 2] * sg[index * 2 + 1];
    } while (index > 1);
}

void sg_clear(int n_indices) {
    for (int i = 0; i < n_indices; ++i) {
        sg_set(i, {});
    }
}

desk sg_get(int index) { return sg[index + shift]; }

desk sg_get(int lo, int hi) {
    std::function<desk(int, int)> inner = [&inner](int lo, int hi) -> desk {
        if (lo == hi - 1) {
            return sg[lo];
        }
        if (lo % 2) {
            return sg[lo] * inner(lo + 1, hi);
        }
        if (hi % 2) {
            return inner(lo, hi - 1) * sg[hi - 1];
        }
        return inner(lo / 2, hi / 2);
    };
    return inner(lo + shift, hi + shift);
}

struct desk_poss {
    int val = 0;
    int m1 = 0;
    int m2 = 0;
    int di = 0;

    desk_poss(int val, int m1, int m2, int di)
        : val(val), m1(m1), m2(m2), di(di) {}
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> v(2 * n);
    for (auto &e : v) {
        std::cin >> e;
    }

    if (n % 2 == 0) {
        int ma = 0;
        int mi = 2'000'000'001;
        for (int i = 0; i < n / 2; ++i) {
            int s[4]{v[2 * i] + v[2 * i + 1], v[2 * i] + v[2 * i + n + 1],
                     v[2 * i + n] + v[2 * i + n + 1],
                     v[2 * i + n] + v[2 * i + 1]};
            std::sort(s, s + 4);
            ma = std::max(ma, s[2]);
            mi = std::min(mi, s[1]);
        }
        std::cout << ma - mi << '\n';
        return;
    }
    if (n == 1) {
        std::cout << 0 << '\n';
        return;
    }
    std::vector<int> r;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        r.push_back(v[cur]);
        r.push_back(v[cur ^= 1]);
        cur = (cur + n) % (2 * n);
    }
    std::vector<desk_poss> posses;
    for (int d = 0; d < n; ++d) {
        posses.emplace_back(r[2 * d] + r[2 * d + 1], 1, 1, d);
        posses.emplace_back(r[(2 * d + 2 * n - 1) % (2 * n)] + r[2 * d + 1], 0,
                            1, d);
        posses.emplace_back(r[(2 * d + 2 * n - 1) % (2 * n)] +
                                r[(2 * d + 2) % (2 * n)],
                            0, 0, d);
        posses.emplace_back(r[2 * d] + r[(2 * d + 2) % (2 * n)], 1, 0, d);
    }

    sg_clear(n);
    std::sort(posses.begin(), posses.end(),
              [](const auto &a, const auto &b) { return a.val < b.val; });
    int loi = 0;
    int hii = 0;
    int ans = 2'000'000'001;
    while (true) {
        auto d = sg_get(0, n);
        if (d.t[0][0] || d.t[1][1]) {
            auto lop = posses[loi];
            ans = std::min(ans, posses[hii - 1].val - lop.val);
            auto extr = sg_get(lop.di);
            extr.t[lop.m1][lop.m2] = false;
            sg_set(lop.di, extr);
            ++loi;
        } else {
            if (hii == 4 * n) {
                break;
            }
            auto hip = posses[hii];
            auto extr = sg_get(hip.di);
            extr.t[hip.m1][hip.m2] = true;
            sg_set(hip.di, extr);
            ++hii;
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
    while (_--) {
        solve();
    }

    return 0;
}
