#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

ll get(const std::vector<int> &pcnt, const std::vector<ll> &psum,
       std::pair<int, int> seg) {
    int L = seg.first;
    int R = seg.second;
    int cnt = pcnt[R] - pcnt[L];
    return psum[R] - psum[R - cnt];
}

void solve() {
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    std::vector<int> pcnt = {0};
    std::vector<ll> psum = {0ll};
    std::vector<std::pair<int, int>> order;
    for (int i = 0; i < n; i++) {
        order.push_back(std::make_pair(a[i], 1));
    }
    for (int i = 0; i < m; i++) {
        order.push_back(std::make_pair(b[i], 0));
    }
    std::sort(order.begin(), order.end());
    int z = n + m;
    for (int i = 0; i < z; i++) {
        pcnt.push_back(pcnt.back() + order[i].second);
        psum.push_back(psum.back() + order[i].first);
    }
    ll cur = std::accumulate(a.begin(), a.end(), 0LL);
    std::set<std::pair<int, int>> segs;
    for (int i = 0; i < z; i++) {
        segs.insert(std::make_pair(i, i + 1));
    }
    std::map<int, std::vector<int>> events;
    for (int i = 0; i < z - 1; i++) {
        events[order[i + 1].first - order[i].first].push_back(i);
    }
    std::vector<std::pair<int, ll>> ans = {{0, cur}};
    for (auto x : events) {
        int cost = x.first;
        std::vector<int> changes = x.second;
        for (auto i : changes) {
            auto itr = segs.upper_bound(std::make_pair(i, int(1e9)));
            auto itl = std::prev(itr);
            std::pair<int, int> pl = *itl;
            std::pair<int, int> pr = *itr;
            cur -= get(pcnt, psum, pl);
            cur -= get(pcnt, psum, pr);
            std::pair<int, int> p = std::make_pair(pl.first, pr.second);
            cur += get(pcnt, psum, p);
            segs.erase(pl);
            segs.erase(pr);
            segs.insert(p);
        }
        ans.push_back(std::make_pair(cost, cur));
    }
    for (int i = 0; i < q; i++) {
        int k;
        std::cin >> k;
        int pos = std::upper_bound(ans.begin(), ans.end(),
                                   std::make_pair(k + 1, -1ll)) -
                  ans.begin() - 1;
        std::cout << ans[pos].second << '\n';
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
