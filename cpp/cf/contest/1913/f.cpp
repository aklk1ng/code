#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

struct sparse_table {
    std::vector<std::vector<int>> st;
    std::vector<int> pw;

    sparse_table() {}

    sparse_table(const std::vector<int> &a) {
        int n = a.size();
        int logn = 32 - __builtin_clz(n);
        st.resize(logn, std::vector<int>(n));
        for (int i = 0; i < n; i++)
            st[0][i] = a[i];
        for (int j = 1; j < logn; ++j)
            for (int i = 0; i < n; i++) {
                st[j][i] = st[j - 1][i];
                if (i + (1 << (j - 1)) < n)
                    st[j][i] =
                        std::min(st[j][i], st[j - 1][i + (1 << (j - 1))]);
            }
        pw.resize(n + 1);
        pw[0] = pw[1] = 0;
        for (int i = 2; i <= n; ++i) {
            pw[i] = pw[i >> 1] + 1;
        }
    }

    int get(int l, int r) {
        if (l >= r) {
            return 1e9;
        }
        int len = pw[r - l];
        return std::min(st[len][l], st[len][r - (1 << len)]);
    }
};

struct suffix_array {
    std::vector<int> c, pos;
    std::vector<std::pair<std::pair<int, int>, int>> p, nw;
    std::vector<int> cnt;
    int n;

    void radix_sort(int max_al) {
        cnt.assign(max_al, 0);
        for (int i = 0; i < n; i++) {
            ++cnt[p[i].first.second];
        }
        for (int i = 1; i < max_al; ++i) {
            cnt[i] += cnt[i - 1];
        }
        nw.resize(n);
        for (int i = 0; i < n; i++) {
            nw[--cnt[p[i].first.second]] = p[i];
        }
        cnt.assign(max_al, 0);
        for (int i = 0; i < n; i++) {
            ++cnt[nw[i].first.first];
        }
        for (int i = 1; i < max_al; ++i) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = n - 1; i >= 0; --i) {
            p[--cnt[nw[i].first.first]] = nw[i];
        }
    }

    std::vector<int> lcp;
    sparse_table st;

    int get_lcp(int l, int r) {
        l = c[l], r = c[r];
        if (l > r) {
            std::swap(l, r);
        }
        return st.get(l, r);
    }

    suffix_array(const std::string &s) {
        n = s.size();
        c = std::vector<int>(s.begin(), s.end());
        int max_al = *std::max_element(c.begin(), c.end()) + 1;
        p.resize(n);
        for (int k = 1; k < n; k <<= 1) {
            for (int i = 0, j = k; i < n; ++i, j = (j + 1 == n ? 0 : j + 1)) {
                p[i] = std::make_pair(std::make_pair(c[i], c[j]), i);
            }
            radix_sort(max_al);
            c[p[0].second] = 0;
            for (int i = 1; i < n; ++i) {
                c[p[i].second] =
                    c[p[i - 1].second] + (p[i].first != p[i - 1].first);
            }
            max_al = c[p.back().second] + 1;
        }
        lcp.resize(n);
        int l = 0;
        for (int i = 0; i < n; i++) {
            l = std::max(0, l - 1);
            if (c[i] == n - 1) {
                continue;
            }
            while (i + l < n && p[c[i] + 1].second + l < n &&
                   s[i + l] == s[p[c[i] + 1].second + l]) {
                ++l;
            }
            lcp[c[i]] = l;
        }
        pos.resize(n);
        for (int i = 0; i < n; i++) {
            pos[i] = p[i].second;
        }
        st = sparse_table(lcp);
    }
};

void solve() {
    std::string s;
    int n;
    std::cin >> n;
    std::cin >> s;

    std::string t = s;
    std::reverse(t.begin(), t.end());
    auto sa = suffix_array(s + "#" + t + "$");
    std::vector<std::vector<int>> ev0(n), ev1(n);
    ll base = 0;
    std::vector<ll> dt(n + 2);
    std::vector<int> d1(n);
    for (int i = 0; i < n; i++) {
        int len0 = sa.get_lcp(i, 2 * n - i + 1);
        base += len0;
        dt[i - len0] += 1;
        dt[i] -= 1;
        dt[i + 1] -= 1;
        dt[i + len0 + 1] += 1;
        if (i - len0 - 1 >= 0 && i + len0 < n) {
            ev0[i - len0 - 1].push_back(i);
            ev0[i + len0].push_back(i);
        }
        int len1 = sa.get_lcp(i, 2 * n - i);
        d1[i] = len1;
        dt[i - len1 + 1] += 1;
        dt[i + 1] -= 2;
        dt[i + len1 + 1] += 1;
        base += len1;
        if (i - len1 >= 0 && i + len1 < n) {
            ev1[i - len1].push_back(i);
            ev1[i + len1].push_back(i);
        }
    }
    std::vector<ll> dx(n + 1);
    ll curt = 0, val = 0;
    for (int i = 0; i < n; i++) {
        curt += dt[i];
        val += curt;
        dx[i] = val;
    }
    ll ans = base;
    int pos = -1, nc = -1;
    bool gr = false;
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            if (c != s[i] - 'a') {
                ll cur = base;
                for (int j : ev0[i]) {
                    if (j <= i && c == s[2 * j - i - 1] - 'a') {
                        cur += 1 + sa.get_lcp(i + 1, 2 * n - (2 * j - i - 2));
                    } else if (j > i && c == s[2 * j - i - 1] - 'a') {
                        cur += 1 + sa.get_lcp(2 * j - i, 2 * n - (i - 1));
                    }
                }
                for (int j : ev1[i]) {
                    if (c != s[2 * j - i] - 'a') {
                        continue;
                    }
                    if (j < i) {
                        cur += 1 + sa.get_lcp(i + 1, 2 * n - (2 * j - i - 1));
                    } else {
                        cur += 1 + sa.get_lcp(2 * j - i + 1, 2 * n - (i - 1));
                    }
                }
                cur += d1[i];
                cur -= dx[i];
                bool upd = false;
                if (cur > ans) {
                    upd = true;
                } else if (cur == ans) {
                    if (c < s[i] - 'a') {
                        if (pos == -1 || gr) {
                            upd = true;
                        }
                    } else {
                        if (pos < i && gr) {
                            upd = true;
                        }
                    }
                }
                if (upd) {
                    ans = cur;
                    pos = i;
                    nc = c;
                    gr = c > s[i] - 'a';
                }
            }
        }
    }
    std::cout << ans << '\n';
    if (pos != -1) {
        s[pos] = nc + 'a';
    }
    std::cout << s << '\n';
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
