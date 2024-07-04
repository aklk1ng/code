#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::string s1, s2;
    std::cin >> s1 >> s2;

    std::map<std::pair<int, int>, int> mp;
    std::set<std::pair<int, int>> st;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        std::pair<int, int> p = {s1[i], s2[n - i - 1]};
        if (p.first > p.second) {
            p = {p.second, p.first};
        }
        if (st.count(p)) {
            mp[p]++;
            if (mp[p] % 2) {
                cnt2++;
                if (p.first == p.second) {
                    cnt1++;
                }
            } else {
                cnt2--;
                if (p.first == p.second) {
                    cnt1--;
                }
            }
        } else {
            st.insert(p);
            mp[p] = 1;
            cnt2++;
            if (p.first == p.second) {
                cnt1++;
            }
        }
    }
    if (n % 2 == cnt1 && cnt2 == cnt1) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
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
