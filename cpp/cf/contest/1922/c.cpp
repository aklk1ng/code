#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 200'000;
const int INF = 1'000'000'009;
int t;

char type(const std::vector<int> &a, int id) {
    int distL = (id == 0 ? INF : a[id] - a[id - 1]);
    int distR = (id + 1 == a.size() ? INF : a[id + 1] - a[id]);
    if (distL < distR) {
        return 'L';
    }
    if (distL > distR) {
        return 'R';
    }
    assert(false);
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> l(n), r(n);
    for (int i = 1; i < n; ++i) {
        r[i] = r[i - 1] + (type(a, i - 1) == 'R' ? 1 : a[i] - a[i - 1]);
    }
    for (int i = n - 2; i >= 0; --i) {
        l[i] = l[i + 1] + (type(a, i + 1) == 'L' ? 1 : a[i + 1] - a[i]);
    }
    int m;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        --x, --y;
        if (x < y) {
            std::cout << r[y] - r[x] << '\n';
        } else {
            std::cout << l[y] - l[x] << '\n';
        }
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
