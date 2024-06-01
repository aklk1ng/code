#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
int n, m;

std::pair<int, int> norm(const std::pair<int, int> &a) {
    return std::make_pair(fmin(a.first, n), std::min(a.second, m));
}

bool good(const std::pair<int, int> &a) {
    return a.first == n || a.second == m;
}

bool comp(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    if (a.first != b.first) {
        return a.first > b.first;
    }
    return a.second > b.second;
}

void solve() {
    std::cin >> n >> m;
    int v;
    std::cin >> v;
    std::set<std::pair<int, int>> s;
    for (int i = 0; i < v; i++) {
        int x, y;
        std::cin >> x >> y;
        s.insert(std::make_pair(x, y));
    }

    int steps = 0;
    std::vector<std::pair<int, int>> cur;
    cur.push_back(std::make_pair(1, 1));
    while (true) {
        if (cur[0] == std::make_pair(n, m)) {
            break;
        }
        std::vector<std::pair<int, int>> ncur;
        for (auto x : cur) {
            int sum = x.first + x.second;
            if (s.count(x)) {
                sum++;
            }
            std::pair<int, int> z = x;
            z.first = sum;
            ncur.push_back(norm(z));
            z = x;
            z.second = sum;
            ncur.push_back(norm(z));
        }
        std::sort(ncur.begin(), ncur.end(), comp);
        int mx = 0;
        std::vector<std::pair<int, int>> ncur2;
        for (auto x : ncur) {
            if (x.second <= mx) {
                continue;
            }
            mx = std::max(mx, x.second);
            ncur2.push_back(x);
        }
        cur = ncur2;
        steps++;
    }
    std::cout << steps << '\n';
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
