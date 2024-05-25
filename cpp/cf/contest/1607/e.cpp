#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::string s;
    std::cin >> s;

    int bx = 0, by = 0;
    int min_bx = 0, max_bx = 0, min_by = 0, max_by = 0;
    for (char c : s) {
        if (c == 'L') {
            min_by = std::min(min_by, --by);
        } else if (c == 'R') {
            max_by = std::max(max_by, ++by);
        } else if (c == 'U') {
            min_bx = std::min(min_bx, --bx);
        } else {
            max_bx = std::max(max_bx, ++bx);
        }

        if (max_bx - min_bx >= n) {
            if (bx == min_bx) {
                min_bx++;
            }
            break;
        }
        if (max_by - min_by >= m) {
            if (by == min_by) {
                min_by++;
            }
            break;
        }
    }

    std::cout << 1 - min_bx << ' ' << 1 - min_by << '\n';
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
