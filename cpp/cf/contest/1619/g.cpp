#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
int k;

std::map<int, std::vector<int>> mx;
std::map<int, std::vector<int>> my;
std::map<std::pair<int, int>, bool> used;
std::map<std::pair<int, int>, int> time_of;

int dfs(int x, int y) {
    used[{x, y}] = true;
    int _min_ = time_of[{x, y}];

    auto i = std::lower_bound(mx[x].begin(), mx[x].end(), y);
    auto j = std::lower_bound(my[y].begin(), my[y].end(), x);

    if (++i != mx[x].end() && !used[{x, *i}] && abs(*i - y) <= k) {
        _min_ = std::min(_min_, dfs(x, *i));
    }
    --i;
    if (i != mx[x].begin() && !used[{x, *(--i)}] && abs(*i - y) <= k) {
        _min_ = std::min(_min_, dfs(x, *i));
    }

    if (++j != my[y].end() && !used[{*j, y}] && abs(*j - x) <= k) {
        _min_ = std::min(_min_, dfs(*j, y));
    }
    --j;
    if (j != my[y].begin() && !used[{*(--j), y}] && abs(*j - x) <= k) {
        _min_ = std::min(_min_, dfs(*j, y));
    }

    return _min_;
}

void solve() {
    mx.clear();
    my.clear();
    used.clear();

    int n;
    std::cin >> n >> k;
    std::vector<std::pair<int, int>> a(n);
    int x, y, timer;

    for (int i = 0; i < n; ++i) {
        std::cin >> x >> y >> timer;
        a[i] = {x, y};
        time_of[{x, y}] = timer;
        mx[x].push_back(y);
        my[y].push_back(x);
    }
    std::vector<int> res;

    for (auto now : mx) {
        std::sort(mx[now.first].begin(), mx[now.first].end());
    }
    for (auto now : my) {
        std::sort(my[now.first].begin(), my[now.first].end());
    }

    for (auto now : a) {
        if (!used[now]) {
            res.push_back(dfs(now.first, now.second));
        }
    }
    std::sort(res.begin(), res.end());

    int ans = res.size() - 1;
    for (int i = 0; i < res.size(); ++i) {
        ans = std::min(ans, std::max((int)res.size() - i - 2, res[i]));
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
