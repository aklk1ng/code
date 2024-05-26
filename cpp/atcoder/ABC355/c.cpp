#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> r(N), c(N);

    int d1 = 0, d2 = 0;
    for (int i = 1; i <= M; i++) {
        int A;
        std::cin >> A;
        A--;

        int x = A / N, y = A % N;
        r[x]++;
        c[y]++;
        if (x == y) {
            d1++;
        }
        if (x + y == N - 1) {
            d2++;
        }
        if (r[x] == N || c[y] == N || d1 == N || d2 == N) {
            std::cout << i << '\n';
            return;
        }
    }
    std::cout << "-1\n";
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
