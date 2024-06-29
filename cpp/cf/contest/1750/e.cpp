#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

struct bit {
    std::vector<int> a;

    void resize(int n) { a = std::vector<int>(n + 1); }

    void update(int pos, int val) {
        int n = (int)a.size() - 1;
        for (int i = pos; i <= n; i += i & (-i)) {
            a[i] += val;
        }
    }

    int query(int pos) {
        int ans = 0;
        for (int i = pos; i; i -= i & (-i)) {
            ans += a[i];
        }
        return ans;
    }

    int query(int st, int dr) { return query(dr) - query(st - 1); }
};

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    s = '$' + s;
    std::vector<int> pref(n + 1);
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + (s[i] == ')' ? -1 : 1);
    }
    std::vector<int> dp(n + 2);
    std::stack<int> paranteze;
    for (int i = n; i >= 1; --i) {
        if (s[i] == '(') {
            if (!paranteze.empty()) {
                dp[i] = dp[paranteze.top() + 1];
                paranteze.pop();
            }
        } else {
            dp[i] = dp[i + 1] + (n - i + 1);
            paranteze.push(i);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += dp[i];
    }
    std::map<int, int> norm;
    std::vector<int> lesgo = pref;
    sort(lesgo.begin(), lesgo.end());
    int p = 1;
    for (int i = 0; i <= n; ++i) {
        if (norm.find(lesgo[i]) == norm.end()) {
            norm[lesgo[i]] = p++;
        }
    }
    for (int i = 0; i <= n; ++i) {
        lesgo[i] = norm[pref[i]];
    }
    p--;
    bit tree;
    tree.resize(p);
    for (int i = 0; i <= n; ++i) {
        ans += tree.query(1, lesgo[i]) * pref[i];
        tree.update(lesgo[i], 1);
    }
    tree.resize(p);
    for (int i = n; i >= 0; --i) {
        ans += tree.query(lesgo[i], p) * -pref[i];
        tree.update(lesgo[i], 1);
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
