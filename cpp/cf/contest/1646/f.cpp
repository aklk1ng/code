#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

const int N = 1010;
int c[N][N];
std::vector<int> extras[N];

void solve() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            std::cin >> x;
            x--;
            c[i][x]++;
            if (c[i][x] > 1) {
                extras[i].push_back(x);
            }
        }
    }

    std::vector<std::vector<int>> res;
    while (true) {
        std::vector<int> oper(n);
        int s = -1;
        for (int i = 0; i < n; i++) {
            if (extras[i].size()) {
                s = i;
                break;
            }
        }
        if (s == -1) {
            break;
        }
        int last_card = -1;
        for (int i = s; i < s + n; i++) {
            int real_i = i % n;
            if (extras[real_i].size()) {
                last_card = extras[real_i].back();
                extras[real_i].pop_back();
            }
            oper[real_i] = last_card;
        }
        res.push_back(oper);
        for (int i = 0; i < n; i++) {
            int i_next = (i + 1) % n;
            c[i][oper[i]]--;
            c[i_next][oper[i]]++;
        }
        for (int i = 0; i < n; i++) {
            int i_next = (i + 1) % n;
            if (c[i_next][oper[i]] > 1) {
                extras[i_next].push_back(oper[i]);
            }
        }
    }
    for (int j = 1; j < n; j++) {
        std::vector<int> oper;
        for (int i = 0; i < n; i++) {
            oper.push_back((i - j + n) % n);
        }
        for (int i = 0; i < j; i++) {
            res.push_back(oper);
        }
    }
    std::cout << res.size() << "\n";
    for (auto i : res) {
        for (auto j : i) {
            std::cout << j + 1 << " ";
        }
        std::cout << "\n";
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
