#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

std::vector<int> ans;
int n;

void add_op(int pos) { ans.push_back(pos % n); }

void f(int l, int r) {

    if (r < l) {
        r += n;
    }

    int m = r - l, direction = 0, start = l;
    r--;
    while (l <= r) {
        if (direction == 0) {
            for (int i = r; i >= l; i--) {
                add_op(i);
            }
            l++;
        } else {
            for (int i = l; i <= r; i++) {
                add_op(i);
            }
            r--;
        }
        direction = 1 - direction;
    }
    for (int i = start; i < start + m / 2; i++) {
        add_op(i);
    }
}

void solve() {
    std::cin >> n;

    f(0, n - 1);
    f((n + 1) / 2, (n - 2) / 2);
    f(0, n - 1);
    std::cout << ans.size() << '\n';
    for (auto it : ans) {
        std::cout << it << ' ';
    }
    std::cout << '\n';
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
