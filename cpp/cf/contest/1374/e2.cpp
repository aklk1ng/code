#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int INF = 2e9 + 1;

void updateSt(std::set<std::pair<int, int>> &st,
              std::set<std::pair<int, int>> &fr, int &sum, int need) {
    need = std::max(need, 0);
    while (true) {
        bool useful = false;
        while (size(st) > need) {
            sum -= st.rbegin()->first;
            fr.insert(*st.rbegin());
            st.erase(prev(st.end()));
            useful = true;
        }
        while (size(st) < need && size(fr) > 0) {
            sum += fr.begin()->first;
            st.insert(*fr.begin());
            fr.erase(fr.begin());
            useful = true;
        }
        while (!st.empty() && !fr.empty() &&
               fr.begin()->first < st.rbegin()->first) {
            sum -= st.rbegin()->first;
            sum += fr.begin()->first;
            fr.insert(*st.rbegin());
            st.erase(prev(st.end()));
            st.insert(*fr.begin());
            fr.erase(fr.begin());
            useful = true;
        }
        if (!useful){
            break;
        }
    }
}

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::pair<int, int>> times[4];
    std::vector<int> sums[4];
    for (int i = 0; i < n; ++i) {
        int t, a, b;
        std::cin >> t >> a >> b;
        times[a * 2 + b].push_back({t, i});
    }

    for (int i = 0; i < 4; ++i) {
        std::sort(times[i].begin(), times[i].end());
        sums[i].push_back(0);
        for (auto it : times[i]) {
            sums[i].push_back(sums[i].back() + it.first);
        }
    }

    int ans = INF;
    int pos = INF;
    std::set<std::pair<int, int>> st;
    std::set<std::pair<int, int>> fr;
    int sum = 0;
    std::vector<int> res;
    for (int iter = 0; iter < 2; ++iter) {
        st.clear();
        fr.clear();
        sum = 0;
        int start = 0;
        while (k - start >= size(sums[1]) || k - start >= size(sums[2]) ||
               m - start - (k - start) * 2 < 0) {
            ++start;
        }
        if (start >= size(sums[3])) {
            std::cout << -1 << '\n';
            return;
        }
        int need = m - start - (k - start) * 2;
        for (int i = 0; i < 3; ++i) {
            for (int p = size(times[i]) - 1; p >= (i == 0 ? 0 : k - start);
                 --p) {
                fr.insert(times[i][p]);
            }
        }
        updateSt(st, fr, sum, need);
        for (int cnt = start; cnt < (iter == 0 ? size(sums[3]) : pos); ++cnt) {
            if (k - cnt >= 0) {
                if (cnt + (k - cnt) * 2 + size(st) == m) {
                    if (ans > sums[3][cnt] + sums[1][k - cnt] +
                                  sums[2][k - cnt] + sum) {
                        ans = sums[3][cnt] + sums[1][k - cnt] +
                              sums[2][k - cnt] + sum;
                        pos = cnt + 1;
                    }
                }
            } else {
                if (cnt + size(st) == m) {
                    if (ans > sums[3][cnt] + sum) {
                        ans = sums[3][cnt] + sum;
                        pos = cnt + 1;
                    }
                }
            }
            if (iter == 1 && cnt + 1 == pos) {
                break;
            }
            need -= 1;
            if (k - cnt > 0) {
                need += 2;
                fr.insert(times[1][k - cnt - 1]);
                fr.insert(times[2][k - cnt - 1]);
            }
            updateSt(st, fr, sum, need);
        }
        if (iter == 1) {
            for (int i = 0; i + 1 < pos; ++i) {
                res.push_back(times[3][i].second);
            }
            for (int i = 0; i <= k - pos; ++i) {
                res.push_back(times[1][i].second);
                res.push_back(times[2][i].second);
            }
            for (auto [value, position] : st) {
                res.push_back(position);
            }
        }
    }

    std::cout << ans << '\n';
    for (auto e : res) {
        std::cout << e + 1 << " ";
    }
    std::cout << '\n';
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
