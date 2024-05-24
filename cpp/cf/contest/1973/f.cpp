#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n), b(n);
    std::vector<ll> c(n), qi(q);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }
    for (int i = 0; i < q; i++) {
        std::cin >> qi[i];
    }

    auto prepare = [&](int x, std::vector<int> &dx, std::vector<int> &px,
                       std::vector<int> &cx, std::map<int, int> &mx) {
        std::vector<int> cntx;
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0) {
                px.push_back(i), cntx.push_back(0);
                while (x % i == 0) {
                    cntx.back()++, x /= i;
                }
            }
        if (x > 1) {
            px.push_back(x), cntx.push_back(1);
        }
        dx.push_back(1);
        for (int i = 0; i < px.size(); i++) {
            cx.push_back(dx.size());
            for (int j = 0; j < cx.back() * cntx[i]; j++) {
                dx.push_back(dx[j] * px[i]);
            }
        }
        for (int i = 0; i < dx.size(); i++) {
            mx[dx[i]] = i;
        }
    };
    auto cal = [&]() -> std::vector<ll> {
        int k = std::max(*std::max_element(a.begin(), a.end()),
                         *std::max_element(b.begin(), b.end())) +
                1;
        std::vector<int> g(n);
        for (int i = 0; i < n; i++) {
            g[i] = std::gcd(a[i], b[i]);
        }
        std::vector<std::pair<ll, int>> v;
        std::vector<ll> ans;
        for (int it = 0; it < 2; it++) {
            std::vector<int> da, pa, ca, db, pb, cb;
            std::map<int, int> ma, mb;
            prepare(a[0], da, pa, ca, ma), prepare(b[0], db, pb, cb, mb);
            std::vector<std::vector<ll>> p(da.size(),
                                           std::vector<ll>(db.size(), 0)),
                d(da.size(), std::vector<ll>(db.size(), 0));
            for (int i = 1; i < n; i++) {
                p[ma[std::gcd(a[0], a[i])]][mb[std::gcd(b[0], b[i])]] += 1,
                    d[ma[std::gcd(a[0], a[i])]][mb[std::gcd(b[0], b[i])]] += 0;
                p[ma[std::gcd(a[0], b[i])]][mb[std::gcd(b[0], a[i])]] += 1,
                    d[ma[std::gcd(a[0], b[i])]][mb[std::gcd(b[0], a[i])]] +=
                    c[i];
                p[ma[std::gcd(a[0], g[i])]][mb[std::gcd(b[0], g[i])]] -= 1,
                    d[ma[std::gcd(a[0], g[i])]][mb[std::gcd(b[0], g[i])]] -=
                    c[i];
            }
            for (int ia = 0; ia < ca.size(); ia++)
                for (int i = da.size() - 1; i >= 0; i--)
                    if (da[i] % pa[ia] == 0)
                        for (int j = db.size() - 1; j >= 0; j--) {
                            p[i - ca[ia]][j] += p[i][j];
                            d[i - ca[ia]][j] += d[i][j];
                        }
            for (int ib = 0; ib < cb.size(); ib++)
                for (int i = db.size() - 1; i >= 0; i--)
                    if (db[i] % pb[ib] == 0)
                        for (int j = da.size() - 1; j >= 0; j--) {
                            p[j][i - cb[ib]] += p[j][i];
                            d[j][i - cb[ib]] += d[j][i];
                        }
            for (int i = 0; i < da.size(); i++) {
                for (int j = 0; j < db.size(); j++) {
                    if (p[i][j] >= n - 1) {
                        v.push_back(
                            {d[i][j] + (it ? c[0] : 0ll), da[i] + db[j]});
                    }
                }
            }
            std::swap(a[0], b[0]);
        }
        std::sort(v.begin(), v.end());
        for (int i = 1; i < v.size(); i++) {
            v[i].second = std::max(v[i - 1].second, v[i].second);
        }
        for (ll d : qi) {
            ans.push_back(v[std::lower_bound(v.begin(), v.end(),
                                             std::make_pair(d + 1, 0)) -
                            v.begin() - 1]
                              .second);
        }
        return ans;
    };
    auto ans = cal();
    for (auto &e : ans) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
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
