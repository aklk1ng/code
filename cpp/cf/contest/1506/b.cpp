#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;

    int ans = 1;
    int i = s.find_first_of('*');
    while (true) {
        int j = std::min(n - 1, i + k);
        while (i < j && s[j] == '.') {
            j--;
        }
        if (i == j) {
            break;
        }
        ans++;
        i = j;
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
