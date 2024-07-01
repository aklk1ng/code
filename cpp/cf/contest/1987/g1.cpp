#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

std::vector<int> arr;
std::vector<int> stk[2];

std::vector<std::pair<int, int>> process(int l, int r, int val[]) {
    std::vector<std::pair<int, int>> v;
    int curr = 0;

    for (int x = l; x < r + 1; x++) {
        std::pair<int, int> res = {x, 0};
        while (!v.empty() && arr[v.back().first] < arr[x]) {
            int t = v.back().second;
            v.pop_back();
            if (!v.empty()) {
                v.back().second = std::max(v.back().second, t + 1);
            }
            res.second = std::max(res.second, t + 1);
        }
        v.push_back(res);

        curr = std::max(curr, res.second + (int)v.size());
        val[x] = curr;
    }

    return v;
}

void solve() {
    int n;
    std::cin >> n;
    arr.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> arr[i];
    }
    std::string s;
    std::cin >> s;

    int ans[2][400005];
    int t[400005];
    for (int z = 0; z < 2; z++) {
        auto v = process(1, n, ans[z]);
        stk[z].clear();
        for (auto &[a, b] : v) {
            stk[z].push_back(a);
        }
        std::reverse(arr.begin() + 1, arr.end());
    }
    int mx = ans[0][stk[0][0]] + ans[1][n - stk[0][0] + 1] - 1;
    for (int z = 0; z < 2; z++) {
        for (int x = 0; x < stk[z].size() - 1; x++) {
            process(stk[z][x], stk[z][x + 1], t);
            for (int y = stk[z][x]; y < stk[z][x + 1]; y++) {
                mx = std::max(mx, t[y] + ans[z ^ 1][n - y]);
            }
        }
        std::reverse(arr.begin() + 1, arr.end());
    }
    std::cout << mx - 1 << '\n';
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
