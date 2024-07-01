#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

std::array<std::vector<int>, 2> get_l_and_r(std::vector<int> &p) {
    int n = p.size();

    std::vector<int> l(n), r(n);

    std::stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && p[s.top()] < p[i]) {
            s.pop();
        }

        if (s.empty()) {
            l[i] = -1;
        } else {
            l[i] = s.top();
        }

        s.push(i);
    }

    s = {};
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && p[s.top()] < p[i]) {
            s.pop();
        }

        if (s.empty()) {
            r[i] = n;
        } else {
            r[i] = s.top();
        }

        s.push(i);
    }

    return {l, r};
}

int ans_l_edge(std::array<int, 2> d, std::array<int, 2> e) {
    return d[0] + 1 + std::max(d[1], e[0]);
}

int ans_r_edge(std::array<int, 2> d, std::array<int, 2> e) {
    return e[1] + 1 + std::max(d[1], e[0]);
}

std::array<int, 2> add_l_edge(std::array<int, 2> d, std::array<int, 2> e) {
    return {std::max({d[0], d[1] + 1, e[0] + 1}), e[1]};
}

std::array<int, 2> add_r_edge(std::array<int, 2> d, std::array<int, 2> e) {
    return {d[0], std::max({d[1] + 1, e[0] + 1, e[1]})};
}

std::vector<std::array<int, 2>>
process_dp(std::vector<std::array<int, 2>> &dp) {
    std::array<int, 2> max_a = {-1, -1}, max_b = {-1, -1}, max_s = {-1, -1};

    for (auto [a, b] : dp) {
        if (a > max_a[0] || (a == max_a[0] && b > max_a[1])) {
            max_a = {a, b};
        }

        if (b > max_b[1] || (b == max_b[1] && a > max_b[0])) {
            max_b = {a, b};
        }

        if (a + b > max_s[0] + max_s[1]) {
            max_s = {a, b};
        }
    }

    return {max_a, max_b, max_s};
}

void add_to_map(std::map<std::array<int, 2>, int> &dp_ind, int &len_dp,
                std::array<int, 2> a) {
    if (!dp_ind.count(a)) {
        dp_ind[a] = len_dp++;
    }
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    std::string s;
    std::cin >> s;

    auto [l, r] = get_l_and_r(p);

    for (int i = 0; i < n; i++) {
        if (p[i] == n) {
            continue;
        }
        if (l[i] == -1 && s[i] == 'L') {
            std::cout << -1 << '\n';
            return;
        }
        if (r[i] == n && s[i] == 'R') {
            std::cout << -1 << '\n';
            return;
        }
    }

    int ans = 0;

    std::vector<int> q(n + 1);
    for (int i = 0; i < n; i++) {
        q[p[i]] = i;
    }

    int len_dp = 0;
    std::map<std::array<int, 2>, int> dp_ind;

    for (int x = 1; x <= n; x++) {
        int i = q[x];
        int tl = l[i], tr = r[i];

        add_to_map(dp_ind, len_dp, {tl, i});
        add_to_map(dp_ind, len_dp, {i, tr});
        add_to_map(dp_ind, len_dp, {tl, tr});
    }

    std::vector<std::vector<std::array<int, 2>>> dp(len_dp, {{0, 0}});
    for (int x = 1; x <= n; x++) {
        int i = q[x];
        int tl = l[i], tr = r[i];

        int ind_l = dp_ind[{tl, i}];
        int ind_r = dp_ind[{i, tr}];
        int ind_c = dp_ind[{tl, tr}];

        for (auto const &d : dp[ind_l]) {
            for (auto const &e : dp[ind_r]) {
                ans = std::max(ans, d[1] + e[0]);

                if (tl >= 0 && s[i] != 'R') {
                    ans = std::max(ans, ans_l_edge(d, e));
                    dp[ind_c].push_back(add_l_edge(d, e));
                }

                if (tr <= n - 1 && s[i] != 'L') {
                    ans = std::max(ans, ans_r_edge(d, e));
                    dp[ind_c].push_back(add_r_edge(d, e));
                }
            }
        }

        dp[ind_c] = process_dp(dp[ind_c]);
    }

    std::cout << ans << '\n';
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
