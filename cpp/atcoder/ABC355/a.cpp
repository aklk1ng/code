#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int A, B;
    std::cin >> A >> B;

    if (A == B) {
        std::cout << "-1\n";
    } else {
        std::cout << (A ^ B) << '\n';
    }
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
