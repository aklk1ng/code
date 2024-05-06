#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    int l = 0, cnt = 0;
    while (l + 1 < n) {
        if (s[l] == '(' || (s[l] == ')' && s[l + 1] == ')')) {
            l += 2;
        } else {
            int r = l + 1;
            while (r < n && s[r] != ')') {
                r++;
            }
            if (r == n) {
                break;
            }
            l = r + 1;
        }
        cnt++;
    }
    std::cout << cnt << ' ' << n - l << '\n';
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
