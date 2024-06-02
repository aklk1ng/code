#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int N, L, R;
    std::cin >> N >> L >> R;
    std::vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) {
        A[i] = i;
    }

    std::reverse(A.begin() + L, A.begin() + R + 1);
    for (int i = 1; i <= N; i++) {
        std::cout << A[i] << " \n"[i == N];
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
