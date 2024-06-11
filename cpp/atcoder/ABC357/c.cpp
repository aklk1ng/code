#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, l = 1;
    char a[729][730];
    for (int i = 0; i < 729; i++) {
        for (int j = 0; j < 730; j++) {
            a[i][j] = 0;
        }
    }
    std::cin >> n;

    a[0][0] = '#';
    for (int k = 0; k < n; k++) {
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                if ((x == 0) && (y == 0)) {
                    continue;
                }
                if ((x == 1) && (y == 1)) {
                    for (int i = 0; i < l; i++) {
                        for (int j = 0; j < l; j++) {
                            a[x * l + i][y * l + j] = '.';
                        }
                    }
                } else {
                    for (int i = 0; i < l; i++) {
                        for (int j = 0; j < l; j++) {
                            a[x * l + i][y * l + j] = a[i][j];
                        }
                    }
                }
            }
        }
        l *= 3;
    }
    for (int i = 0; i < l; i++) {
        std::cout << a[i] << '\n';
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
