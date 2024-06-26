#include <bits/stdc++.h>
using ll = long long;
const int inf = 1e9 + 7;

struct SegTree {
    std::vector<int> mn, mx;
    int n;

    SegTree(int _n) : n(_n) {
        mx.assign(2 * n, -inf);
        mn.resize(2 * n, inf);
    }

    void upd(int pos, int val) {
        mx[pos + n] = val;
        mn[pos + n] = val;
        pos = (pos + n) >> 1;
        for (; pos > 0; pos >>= 1) {
            mx[pos] = std::max(mx[pos << 1], mx[(pos << 1) | 1]);
            mn[pos] = std::min(mn[pos << 1], mn[(pos << 1) | 1]);
        }
    }

    std::pair<int, int> get(int l, int r) {
        std::pair<int, int> res = {-inf, inf};
        l += n;
        r += n + 1;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                res.first = std::max(res.first, mx[l]);
                res.second = std::min(res.second, mn[l++]);
            }
            if (r & 1) {
                res.first = std::max(res.first, mx[--r]);
                res.second = std::min(res.second, mn[r]);
            }
        }
        return res;
    }
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    SegTree tree(n);
    std::set<int> st;
    for (int i = 0; i < n; i++) {
        tree.upd(i, a[i]);
        if (i > 0 && a[i] < a[i - 1]) {
            st.insert(i);
        }
    }

    auto find_pref = [&](int pos, int x) {
        if (pos < 0) {
            return 0;
        }
        int l = 0, r = pos;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (a[m] > x) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return r + 1;
    };

    auto find_suff = [&](int pos, int x) {
        if (pos >= n) {
            return n - 1;
        }
        int l = pos, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (a[m] >= x) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return r;
    };

    auto query = [&]() {
        if (st.empty()) {
            std::cout << -1 << ' ' << -1 << '\n';
            return;
        }
        int l = *st.begin() - 1;
        int r = *(--st.end());

        auto [mx, mn] = tree.get(l, r);

        std::cout << find_pref(l - 1, mn) + 1 << ' ' << find_suff(r + 1, mx) + 1
                  << '\n';
    };

    query();
    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int pos, val;
        std::cin >> pos >> val;
        pos--;
        if (pos > 0 && a[pos] < a[pos - 1]) {
            st.erase(pos);
        }
        if (pos + 1 < n && a[pos + 1] < a[pos]) {
            st.erase(pos + 1);
        }
        a[pos] = val;
        tree.upd(pos, val);
        if (pos > 0 && a[pos] < a[pos - 1]) {
            st.insert(pos);
        }
        if (pos + 1 < n && a[pos + 1] < a[pos]) {
            st.insert(pos + 1);
        }
        query();
    }
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
