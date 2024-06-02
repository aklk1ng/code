#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

ll crs(std::pair<ll, ll> a, std::pair<ll, ll> b) {
    return a.first * b.second - a.second * b.first;
}

std::pair<ll, ll> sub(std::pair<ll, ll> a, std::pair<ll, ll> b) {
    return {a.first - b.first, a.second - b.second};
}

bool plcomp(std::pair<ll, ll> a, std::pair<ll, ll> b) {
    return (a.first * b.second < b.first * a.second);
}

void solve() {
    ll n;
    std::cin >> n;
    std::set<std::pair<ll, ll>> st;
    for (ll i = 0; i < n; i++) {
        std::pair<ll, ll> ca;
        std::cin >> ca.second >> ca.first;
        st.insert(ca);
    }
    n = st.size();
    std::vector<std::pair<ll, ll>> a;
    for (auto &nx : st) {
        a.push_back(nx);
    }
    if (n >= 3) {
        std::vector<std::pair<ll, ll>> g1, g2;
        g1.push_back(a[0]);
        g1.push_back(a[1]);
        g2.push_back(a[0]);
        g2.push_back(a[1]);
        for (ll i = 2; i < n; i++) {
            while (g1.size() >= 2 &&
                   crs(sub(g1[g1.size() - 1], g1[g1.size() - 2]),
                       sub(a[i], g1[g1.size() - 1])) <= 0) {
                g1.pop_back();
            }
            while (g2.size() >= 2 &&
                   crs(sub(g2[g2.size() - 1], g2[g2.size() - 2]),
                       sub(a[i], g2[g2.size() - 1])) >= 0) {
                g2.pop_back();
            }
            g1.push_back(a[i]);
            g2.push_back(a[i]);
        }
        a.clear();
        for (ll i = 0; i < g1.size(); i++) {
            a.push_back(g1[i]);
        }
        for (ll i = (ll)g2.size() - 2; i >= 1; i--) {
            a.push_back(g2[i]);
        }
    }
    n = a.size();
    ll omega = 0, alpha = 0;
    for (ll i = 0; i < n; i++) {
        if (a[omega].first < a[i].first) {
            omega = i;
        }
        if (plcomp(a[alpha], a[i])) {
            alpha = i;
        }
    }
    ll q;
    std::cin >> q;
    while (q > 0) {
        q--;
        ll pow, dist;
        std::cin >> pow >> dist;
        if (pow * a[alpha].first < dist * a[alpha].second) {
            std::cout << "-1\n";
            continue;
        }
        if (pow * a[omega].first >= dist * a[omega].second) {
            double cres = dist;
            cres /= a[omega].first;
            std::cout << std::fixed << std::setprecision(12) << cres << "\n";
            continue;
        }
        ll p1, p2;
        {
            ll lef = alpha;
            ll rig = omega;
            if (lef > rig) {
                rig += n;
            }
            while (lef <= rig) {
                ll te = (lef + rig) / 2;
                ll i = te % n;
                if (pow * a[i].first >= dist * a[i].second) {
                    lef = te + 1;
                } else {
                    rig = te - 1;
                }
            }
            p1 = (rig % n);
            p2 = (lef % n);
        }
        double rv = ((double)dist) / ((double)a[p1].first);
        double lef = 0.0, rig = 1.0;
        for (ll tr = 0; lef <= rig && tr < 100; tr++) {
            double te = (lef + rig) / 2.0;
            double fir =
                (1.0 - te) * ((double)a[p1].first) + te * ((double)a[p2].first);
            double sec = (1.0 - te) * ((double)a[p1].second) +
                         te * ((double)a[p2].second);
            if (((double)pow) * fir >= ((double)dist) * sec) {
                rv = std::min(rv, ((double)dist) / ((double)fir));
                lef = te;
            } else {
                rig = te;
            }
        }
        std::cout << std::fixed << std::setprecision(12) << rv << "\n";
    }
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
