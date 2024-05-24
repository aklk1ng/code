#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    int ori = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
        ori |= v[i];
    }

    auto check = [&](int mid) {
        std::vector<int> frekbit(31);
        for (int i = 0; i < mid; i++) {
            int x = v[i];

            for (int j = 30; j >= 0; j--) {
                if (x >= (1 << j)) {
                    x -= (1 << j);
                    frekbit[j]++;
                }
            }
        }
        int or2 = 0;
        for (int i = 0; i < frekbit.size(); i++) {
            if (frekbit[i] > 0) {
                or2 += (1 << i);
            }
        }
        if (or2 != ori) {
            return false;
        }
        for (int i = 1; i + mid - 1 < v.size(); i++) {
            int x = v[i - 1];
            for (int j = 30; j >= 0; j--) {
                if (x >= (1 << j)) {
                    x -= (1 << j);
                    frekbit[j]--;
                    if (frekbit[j] == 0) {
                        or2 -= (1 << j);
                    }
                }
            }
            x = v[i + mid - 1];
            for (int j = 30; j >= 0; j--) {
                if (x >= (1 << j)) {
                    x -= (1 << j);
                    frekbit[j]++;
                    if (frekbit[j] == 1) {
                        or2 += (1 << j);
                    }
                }
            }
            if (or2 != ori) {
                return false;
            }
        }
        return true;
    };
    int l = 1, h = n;
    while (l < h) {
        int m = (l + h) / 2;
        if (check(m)) {
            h = m;
        } else {
            l = m + 1;
        }
    }
    std::cout << l << '\n';
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
