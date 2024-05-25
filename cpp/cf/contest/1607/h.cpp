#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

struct seg {
    int a, b, m;
    int index;
};

int n, ans;
std::vector<seg> segs;
std::map<int, std::vector<seg>> diags;

void erase(std::multiset<std::pair<std::pair<int, int>, int>> &lr, int l, int r,
           int index) {
    std::pair<std::pair<int, int>, int> plr =
        std::make_pair(std::make_pair(l, r), index);
    auto i = lr.find(plr);
    assert(i != lr.end());
    lr.erase(i);
}

void erase(std::multiset<std::pair<std::pair<int, int>, int>> &lr,
           std::multiset<std::pair<std::pair<int, int>, int>> &rl, int l, int r,
           int index) {
    erase(lr, l, r, index);
    erase(rl, r, l, index);
}

std::map<int, std::pair<int, int>> dd;

void setup_dd(int index, int value) {
    assert(dd.count(index) == 0);
    int x = segs[index].a - value;
    int y = segs[index].m - x;
    assert(segs[index].a - x >= 0);
    assert(segs[index].b - y >= 0);
    assert(x + y == segs[index].m);
    dd[index] = std::make_pair(x, y);
}

int cal(std::vector<seg> s) {
    int n = s.size();
    std::multiset<std::pair<std::pair<int, int>, int>> lr, rl;
    for (int i = 0; i < n; i++) {
        int min_d = std::max(s[i].m - s[i].b, 0);
        int max_d = std::min(s[i].a, s[i].m);
        lr.insert(std::make_pair(std::make_pair(s[i].a - max_d, s[i].a - min_d),
                                 s[i].index));
        rl.insert(std::make_pair(std::make_pair(s[i].a - min_d, s[i].a - max_d),
                                 s[i].index));
    }

    int result = 0;
    while (!rl.empty()) {
        result++;
        auto min_r_iterator = rl.begin();

        auto [r, l] = min_r_iterator->first;
        int index = min_r_iterator->second;
        erase(lr, rl, l, r, index);
        setup_dd(index, r);

        while (!lr.empty()) {
            auto min_l_iterator = lr.begin();
            auto [lo, hi] = min_l_iterator->first;
            int ii = min_l_iterator->second;
            if (lo <= r) {
                erase(lr, rl, lo, hi, ii);
                setup_dd(ii, r);
            } else {
                break;
            }
        }
    }

    return result;
}

void solve() {
    std::cin >> n;
    diags.clear();
    dd.clear();
    segs = std::vector<seg>(n);
    for (int i = 0; i < n; i++) {
        seg s;
        s.index = i;
        std::cin >> s.a >> s.b >> s.m;
        diags[s.a + s.b - s.m].push_back(s);
        segs[i] = s;
    }
    int sum = 0;
    for (auto p : diags) {
        sum += cal(p.second);
    }
    std::cout << sum << '\n';
    for (int i = 0; i < n; i++) {
        std::cout << dd[i].first << " " << dd[i].second << '\n';
    }
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
