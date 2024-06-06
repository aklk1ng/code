#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, f, k;
    std::cin >> n >> f >> k;
    f--;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int gt = 0, eq = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > a[f]) {
            gt++;
        } else if (a[i] == a[f]) {
            eq++;
        }
    }
    if (k <= gt) {
        std::cout << "NO\n";
    } else if (k >= gt + eq) {
        std::cout << "YES\n";
    } else {
        std::cout << "MAYBE\n";
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
