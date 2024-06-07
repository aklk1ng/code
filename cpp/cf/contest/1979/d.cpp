#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;

    int x = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == s[n - 1]) {
            x++;
        } else {
            break;
        }
    }
    auto check = [&]() {
        for (int i = 0; i < k; i++) {
            if (s[i] != s[0]) {
                return false;
            }
        }
        for (int i = 0; i < n - k; i++) {
            if (s[i] == s[i + k]) {
                return false;
            }
        }
        return true;
    };
    auto op = [&](int p) {
        std::reverse(s.begin(), s.begin() + p);
        s = s.substr(p, s.size() - p) + s.substr(0, p);
        if (check()) {
            std::cout << p << "\n";
        } else {
            std::cout << -1 << "\n";
        }
    };
    if (x == k) {
        int p = n;
        for (int i = n - 1 - k; i >= 0; i--) {
            if (s[i] == s[i + k]) {
                p = i + 1;
                break;
            }
        }
        op(p);
    } else if (x > k) {
        std::cout << -1 << "\n";
    } else {
        bool was = false;
        for (int i = 0; i < n; i++) {
            if (s[i] != s.back()) {
                continue;
            }
            int j = i;
            while (j + 1 < n && s[i] == s[j + 1]) {
                j++;
            }
            if (j - i + 1 + x == k) {
                op(j + 1);
                was = true;
                break;
            } else if (j - i + 1 - k + x == k) {
                op(i + k - x);
                was = true;
                break;
            }
            i = j;
        }
        if (!was) {
            op(n);
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
