#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

const int N = 1003;

int n;
int a[N];
std::vector<int> g[N * N];
int mt[N];
bool used[N * N];
std::vector<int> val;

bool kuhn(int x) {
    if (used[x]) {
        return false;
    }
    used[x] = true;
    for (auto y : g[x]) {
        if (mt[y] == -1 || kuhn(mt[y])) {
            mt[y] = x;
            return true;
        }
    }
    return false;
}

void solve() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            val.push_back(a[i] * j);
        }
    }
    std::sort(val.begin(), val.end());
    val.erase(std::unique(val.begin(), val.end()), val.end());
    int v = val.size();
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            int k = std::lower_bound(val.begin(), val.end(), a[i] * j) -
                    val.begin();
            g[k].push_back(i);
        }
    }
    for (int i = 0; i < n; i++) {
        mt[i] = -1;
    }
    for (int i = 0; i < v; i++) {
        if (kuhn(i)) {
            ans += val[i];
            for (int j = 0; j < v; j++) {
                used[j] = false;
            }
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (false) {
        std::cin >> _;
    }
    while (_--) {
        solve();
    }

    return 0;
}
