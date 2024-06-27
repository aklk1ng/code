#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
constexpr int MAX_GIVEN = 200'000;
constexpr int MAX_USED = 400'000;

struct lazy_segtree {
    int n;
    std::vector<int> st;
    std::vector<int> lazy;

    lazy_segtree(int n) : n(n), st(4 * n), lazy(4 * n) {}

    void push(int v, int l, int r) {
        if (l + 1 != r) {
            lazy[2 * v] += lazy[v];
            lazy[2 * v + 1] += lazy[v];
        }
        st[v] += lazy[v];
        lazy[v] = 0;
    }

    void upd(int x, int y, int q) { upd(1, 0, n, x, y, q); }

    void upd(int v, int l, int r, int x, int y, int q) {
        push(v, l, r);
        if (r <= x || l >= y)
            return;
        if (x <= l && r <= y) {
            lazy[v] += q;
            push(v, l, r);
        } else {
            int m = (l + r) / 2;
            upd(2 * v, l, m, x, y, q);
            upd(2 * v + 1, m, r, x, y, q);
            st[v] = std::min(st[2 * v], st[2 * v + 1]);
        }
    }

    int qry(int x, int y) { return qry(1, 0, n, x, y); }

    int qry(int v, int l, int r, int x, int y) {
        push(v, l, r);
        if (r <= x || l >= y) {
            return INT_MAX;
        }
        if (x <= l && r <= y) {
            return st[v];
        }
        int m = (l + r) / 2;
        return std::min(qry(2 * v, l, m, x, y), qry(2 * v + 1, m, r, x, y));
    }
};

std::optional<std::pair<int, int>>
find(const std::set<std::pair<int, int>> &intervals, int x) {
    auto it = intervals.upper_bound({x + 1, INT_MIN});
    if (it == intervals.begin()) {
        return {};
    } else {
        auto p_pair = *prev(it);
        if (p_pair.second >= x) {
            return p_pair;
        } else {
            return {};
        }
    }
}

void add(std::pair<int, int> p, std::set<std::pair<int, int>> &intervals,
         std::set<std::pair<int, int>> &to_add,
         std::set<std::pair<int, int>> &to_remove) {
    std::optional<std::pair<int, int>> prev_range, nxt_range;
    while ((prev_range = find(intervals, p.first - 1))) {
        int overlap = prev_range->second - p.first + 1;
        intervals.erase(*prev_range);
        to_remove.insert(*prev_range);
        p.first = prev_range->first - overlap;
    }

    while ((nxt_range = find(intervals, p.second + 1))) {
        int overlap = p.second - nxt_range->first + 1;
        intervals.erase(*nxt_range);
        to_remove.insert(*nxt_range);
        p.second = nxt_range->second + overlap;
    }

    intervals.insert(p);
    to_add.insert(p);
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> cur(MAX_GIVEN);
    std::set<std::pair<int, int>> intervals;
    lazy_segtree balance(MAX_USED);
    for (int i = 0; i < MAX_USED; i++) {
        balance.upd(i, MAX_USED, -1);
    }
    while (n--) {
        int x;
        std::cin >> x;
        x--;

        std::set<std::pair<int, int>> to_add, to_remove;
        if (cur[x] == 0) {
            cur[x] = 1;
            balance.upd(x, MAX_USED, 2);

            auto cur_range = find(intervals, x);
            if (cur_range) {
                intervals.erase(*cur_range);
                to_remove.insert(*cur_range);
                add({cur_range->first, cur_range->second + 2}, intervals,
                    to_add, to_remove);
            } else {
                auto next_range = find(intervals, x + 1);
                if (next_range) {
                    intervals.erase(*next_range);
                    to_remove.insert(*next_range);
                    add({x, next_range->second + 1}, intervals, to_add,
                        to_remove);
                } else {
                    add({x, x + 1}, intervals, to_add, to_remove);
                }
            }
        } else {
            cur[x] = 0;
            balance.upd(x, MAX_USED, -2);
            auto in_range = find(intervals, x).value();

            int l = in_range.first;
            int r = in_range.second + 1;

            auto rem = l > 0 ? balance.qry(l - 1, l) : 0;
            while (l < r) {
                int m = l + (r - l) / 2;
                int min_balance = balance.qry(in_range.first, m + 1) - rem;

                if (min_balance > -2) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }

            intervals.erase(in_range);
            to_remove.insert(in_range);

            if ((r - 2) - in_range.first + 1 > 0) {
                intervals.insert({in_range.first, r - 2});
                to_add.insert({in_range.first, r - 2});
            }

            if (in_range.second - (r + 1) + 1 > 0) {
                intervals.insert({r + 1, in_range.second});
                to_add.insert({r + 1, in_range.second});
            }
        }

        std::cout << to_remove.size() << '\n';
        for (auto [x, y] : to_remove) {
            std::cout << x + 1 << ' ' << y + 1 << '\n';
        }

        std::cout << to_add.size() << '\n';
        for (auto [x, y] : to_add) {
            std::cout << x + 1 << ' ' << y + 1 << '\n';
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (false) {
        std::cin >> _;
    }
    while (_--) {
        solve();
    }

    return 0;
}
