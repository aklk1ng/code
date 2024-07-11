#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    int a[n], b[n];
    std::vector<std::pair<int, int>> ax, bx;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (i > 0) {
            ax.emplace_back(std::min(a[i - 1], a[i]), std::max(a[i - 1], a[i]));
        }
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        if (i > 0) {
            bx.emplace_back(std::min(b[i - 1], b[i]), std::max(b[i - 1], b[i]));
        }
    }

    std::sort(ax.begin(), ax.end());
    std::sort(bx.begin(), bx.end());
    if (!(a[0] == b[0] && a[n - 1] == b[n - 1] &&
          equal(ax.begin(), ax.end(), bx.begin()))) {
        std::cout << "NO\n";
        return;
    }
    std::cout << "YES\n";
    std::vector<std::pair<int, int>> ans;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == b[i] && a[i + 1] == b[i + 1]) {
            continue;
        }
        int pos = -1;
        for (int j = i; j < n - 1; j++) {
            if (a[j + 1] == b[i] && a[j] == b[i + 1]) {
                pos = j;
                break;
            }
        }
        if (pos != -1) {
            ans.emplace_back(i + 1, pos + 2);
            std::reverse(a + i, a + pos + 2);
            continue;
        }
        for (int j = i; j < n - 1; j++) {
            if (a[j] == b[i] && a[j + 1] == b[i + 1]) {
                pos = j;
                break;
            }
        }
        std::set<std::pair<int, int>> seen;
        for (int j = i; j < pos; j++) {
            seen.insert(std::make_pair(std::min(a[j], a[j + 1]),
                                       std::max(a[j], a[j + 1])));
        }
        int val = -1;
        for (int j = i + 1; j < n - 1; j++) {
            if (seen.find(std::make_pair(std::min(b[j], b[j + 1]),
                                         std::max(b[j], b[j + 1]))) !=
                seen.end()) {
                val = j;
                break;
            }
        }
        int posr = -1, posl = -1;
        for (int j = i; j <= pos; j++) {
            if (std::min(a[j], a[j + 1]) == std::min(b[val], b[val + 1]) &&
                std::max(a[j], a[j + 1]) == std::max(b[val], b[val + 1])) {
                posr = j;
                break;
            }
        }
        for (int j = n - 2; j >= pos; j--) {
            if (std::min(a[j], a[j + 1]) == std::min(b[val - 1], b[val]) &&
                std::max(a[j], a[j + 1]) == std::max(b[val - 1], b[val])) {
                posl = j;
                break;
            }
        }
        if (posr < n - 1 && a[posr + 1] == a[posl]) {
            posr++;
        } else if (posl < n - 1 && a[posr] == a[posl + 1]) {
            posl++;
        } else if (posr < n - 1 && posl < n - 1 && a[posr + 1] == a[posl + 1]) {
            posr++;
            posl++;
        }
        ans.emplace_back(posr + 1, posl + 1);
        std::reverse(a + posr, a + posl + 1);
        pos = -1;
        for (int j = i; j < n - 1; j++) {
            if (a[j + 1] == b[i] && a[j] == b[i + 1]) {
                pos = j;
                break;
            }
        }
        ans.emplace_back(i + 1, pos + 2);
        std::reverse(a + i, a + pos + 2);
    }
    std::cout << ans.size() << '\n';
    for (auto p : ans) {
        std::cout << p.first << ' ' << p.second << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (true) {
        std::cin >> _;
    }
    while (_--) {
        solve();
    }

    return 0;
}
