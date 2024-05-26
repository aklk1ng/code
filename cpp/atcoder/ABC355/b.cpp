#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    auto C = A;
    C.insert(C.end(), B.begin(), B.end());
    std::sort(C.begin(), C.end());
    std::sort(A.begin(), A.end());
    for (int i = 1, j = 0; i < C.size(); i++) {
        while (j < N && A[j] < C[i]) {
            j++;
        }
        if (j < N && j > 0 && A[j] == C[i] && A[j - 1] == C[i - 1]) {
            std::cout << "Yes\n";
            return;
        }
    }
    std::cout << "No\n";
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
