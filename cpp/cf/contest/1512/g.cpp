#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 1e7 + 100;
long long s[N];
int d[N];
int ans[N];

void init() {
    std::fill(d, d + N, -1);
    d[1] = 1;
    for (int i = 2; i * i < N; i++) {
        if (d[i] == -1) {
            d[i] = i;
            for (int j = i * i; j < N; j += i) {
                if (d[j] == -1) {
                    d[j] = i;
                }
            }
        }
    }
    s[1] = 1;
    for (int i = 2; i < N; i++) {
        if (d[i] == -1) {
            d[i] = i;
            s[i] = i + 1;
        } else {
            int j = i;
            s[i] = 1;
            while (j % d[i] == 0) {
                j /= d[i];
                s[i] = s[i] * d[i] + 1;
            }
            s[i] *= s[j];
        }
    }
    std::fill(ans, ans + N, -1);
    for (int i = N - 1; i > 0; i--) {
        if (s[i] < N) {
            ans[s[i]] = i;
        }
    }
}

void solve() {
    int c;
    std::cin >> c;
    std::cout << ans[c] << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    if (true) {
        std::cin >> T;
    }
    init();
    while (T--) {
        solve();
    }

    return 0;
}
