#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;

    std::vector<int> cnt(26);
    for (char c : s) {
        cnt[c - 'a']++;
    }
    for (int len = n; len >= 1; len--) {
        std::vector<bool> used(len);
        std::vector<int> cycles;

        for (int i = 0; i < len; i++) {
            if (used[i]) {
                continue;
            }

            int j = (i + k) % len;
            used[i] = true;
            cycles.push_back(0);
            cycles.back()++;

            while (!used[j]) {
                cycles.back()++;
                used[j] = true;
                j = (j + k) % len;
            }
        }

        std::vector<int> cur_cnt(cnt);

        std::sort(cycles.begin(), cycles.end());
        std::sort(cur_cnt.begin(), cur_cnt.end());

        bool can_fill = true;

        while (!cycles.empty()) {
            if (cur_cnt.back() < cycles.back()) {
                can_fill = false;
                break;
            } else {
                cur_cnt.back() -= cycles.back();
                cycles.pop_back();
                sort(cur_cnt.begin(), cur_cnt.end());
            }
        }

        if (can_fill) {
            std::cout << len << '\n';
            break;
        }
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
