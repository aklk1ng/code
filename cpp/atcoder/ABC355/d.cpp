#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> l(N), r(N);
    for (int i = 0; i < N; i++) {
        std::cin >> l[i] >> r[i];
    }

    std::sort(l.begin(), l.end());
    std::sort(r.begin(), r.end());
    ll ans = 1LL * N * (N - 1) / 2;
    for (int i = 0, j = 0; i < N; i++) {
        while (j < N && r[j] < l[i]) {
            j++;
        }
        ans -= j;
    }
    std::cout << ans << '\n';
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
