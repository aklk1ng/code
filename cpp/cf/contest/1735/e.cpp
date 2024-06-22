#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
bool viv = false;
int n;
std::vector<int> d1, d2;

bool work(int points_diff) {
    int p1 = 0;
    int p2 = points_diff;

    std::multiset<int, std::greater<int>> s1, s2;
    for (auto i : d1) {
        s1.insert(i);
    }
    for (auto i : d2) {
        s2.insert(i);
    }

    auto farthest = [](std::multiset<int, std::greater<int>> &s) {
        return s.empty() ? -1 : *s.begin();
    };
    auto farthest_both = [&]() { return std::max(farthest(s1), farthest(s2)); };

    std::vector<int> ans;
    while (farthest_both() > points_diff) {
        bool choose_s1 = farthest(s1) > farthest(s2);
        auto &s_far = choose_s1 ? s1 : s2;
        auto &s_near = choose_s1 ? s2 : s1;

        int value = *s_far.begin();
        int complem = value - points_diff;
        if (!s_near.count(complem)) {
            return false;
        }

        s_far.erase(s_far.find(value));
        s_near.erase(s_near.find(complem));

        if (choose_s1) {
            ans.push_back(p1 + value);
        } else {
            ans.push_back(p2 - value);
        }
    }

    std::vector<int> left1, left2;
    for (auto i : s1) {
        left1.push_back(i);
    }
    for (auto i : s2) {
        left2.push_back(i);
    }
    std::sort(left1.begin(), left1.end());
    std::sort(left2.rbegin(), left2.rend());

    for (int i = 0; i < left1.size(); i++) {
        if (left1[i] + left2[i] != points_diff) {
            return false;
        }
    }

    for (auto i : left1) {
        ans.push_back(i);
    }

    std::sort(ans.begin(), ans.end());
    int sh = std::max(-ans[0], 0);
    p1 += sh, p2 += sh;
    for (auto &i : ans) {
        i += sh;
    }

    std::cout << "YES\n";
    for (auto i : ans) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    std::cout << p1 << ' ' << p2 << '\n';
    return true;
}

void solve() {
    std::cin >> n;
    d1.resize(n);
    d2.resize(n);
    for (auto &d : d1) {
        std::cin >> d;
    }
    for (auto &d : d2) {
        std::cin >> d;
    }

    int dist1 = d1[0];
    for (auto dist2 : d2) {
        if (work(dist1 + dist2)) {
            return;
        }
        if (work(abs(dist1 - dist2))) {
            return;
        }
    }

    std::cout << "NO\n";
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
