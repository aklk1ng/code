#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int C = 1e5;
const int D = 4e5 + 10;

std::set<std::pair<int, int>> diag[D];

void solve() {
    int n, d;
    std::cin >> n >> d;
    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
        x[i] += C;
        y[i] += C;
    }

    bool found = false;
    {
        for (int i = 0; i < n; i++) {
            diag[x[i] + y[i]].insert({x[i], i});
        }
        for (int i = 0; i < n; i++) {
            auto it1 = diag[x[i] + y[i]].lower_bound({x[i] + d / 2, -1});
            if (it1 == diag[x[i] + y[i]].end() || it1->first != x[i] + d / 2) {
                continue;
            }
            if (x[i] + y[i] + d < D) {
                auto it2 =
                    diag[x[i] + y[i] + d].lower_bound({x[i] + d / 2, -1});
                if (it2 != diag[x[i] + y[i] + d].end() &&
                    it2->first <= it1->first + d / 2) {
                    std::cout << i + 1 << " " << it1->second + 1 << " "
                              << it2->second + 1 << "\n";
                    found = true;
                    break;
                }
            }
            if (x[i] + y[i] - d >= 0) {
                auto it2 =
                    diag[x[i] + y[i] - d].lower_bound({x[i] - d / 2, -1});
                if (it2 != diag[x[i] + y[i] - d].end() &&
                    it2->first <= it1->first - d / 2) {
                    std::cout << i + 1 << " " << it1->second + 1 << " "
                              << it2->second + 1 << "\n";
                    found = true;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            diag[x[i] + y[i]].erase({x[i], i});
        }
    }
    if (!found) {
        for (int i = 0; i < n; i++) {
            y[i] -= 2 * C;
            diag[x[i] - y[i]].insert({x[i], i});
        }
        for (int i = 0; i < n; i++) {
            auto it1 = diag[x[i] - y[i]].lower_bound({x[i] + d / 2, -1});
            if (it1 == diag[x[i] - y[i]].end() || it1->first != x[i] + d / 2) {
                continue;
            }
            if (x[i] - y[i] + d < D) {
                auto it2 =
                    diag[x[i] - y[i] + d].lower_bound({x[i] + d / 2, -1});
                if (it2 != diag[x[i] - y[i] + d].end() &&
                    it2->first <= it1->first + d / 2) {
                    std::cout << i + 1 << " " << it1->second + 1 << " "
                              << it2->second + 1 << "\n";
                    found = true;
                    break;
                }
            }
            if (x[i] - y[i] - d >= 0) {
                auto it2 =
                    diag[x[i] - y[i] - d].lower_bound({x[i] - d / 2, -1});
                if (it2 != diag[x[i] - y[i] - d].end() &&
                    it2->first <= it1->first - d / 2) {
                    std::cout << i + 1 << " " << it1->second + 1 << " "
                              << it2->second + 1 << "\n";
                    found = true;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            diag[x[i] - y[i]].erase({x[i], i});
        }
    }
    if (!found) {
        std::cout << "0 0 0\n";
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
