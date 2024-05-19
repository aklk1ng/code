#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    auto get = [&](int i) { return 'a' + i - 1; };
    int i = n - 1;
    std::string ans;
    while (i >= 0) {
        if (s[i] != '0') {
            ans += get(s[i] - '0');
            i--;
        } else {
            ans += get(std::stoi(s.substr(i - 2, 2)));
            i -= 3;
        }
    }
    std::reverse(ans.begin(), ans.end());
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
