#include <bits/stdc++.h>
typedef long long ll;

struct state {
  std::basic_string<std::array<int, 2>> a;

  friend state add(state x, int d) {
    for (auto &[l, r] : x.a) {
      l += d, r += d;
    }
    return x;
  }

  friend state unite(state x, state y) {
    state z;
    std::merge(x.a.begin(), x.a.end(), y.a.begin(), y.a.end(),
               std::back_inserter(z.a));
    int j = 0;
    for (int i = 1; i < z.a.size(); i++) {
      if (z.a[i][0] <= z.a[j][1] + 1) {
        z.a[j][1] = std::max(z.a[j][1], z.a[i][1]);
      } else {
        z.a[++j] = z.a[i];
      }
    }
    z.a.erase(z.a.begin() + j + 1, z.a.end());
    return z;
  }

  friend bool contains(state x, int k) {
    for (auto &[l, r] : x.a) {
      if (k >= l && k <= r) {
        return true;
      }
    }
    return false;
  }
};

state from_constant(int d) { return state({{{d, d}}}); }

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::string s;
  std::cin >> s;

  std::vector<std::array<state, 2>> dp(n);
  dp[0][0] = from_constant(s[0] != 'A');
  dp[0][1] = from_constant(s[0] != 'B');

  for (int i = 1; i < n; i++) {
    dp[i][0] = add(unite(dp[i - 1][0], add(dp[i - 1][1], 1)),
                   (s[i] != 'A') + (s[i] != s[i - 1]));
    dp[i][1] = add(unite(dp[i - 1][1], add(dp[i - 1][0], 1)),
                   (s[i] != 'B') + (s[i] != s[i - 1]));
  }
  if (!(contains(dp[n - 1][0], k) || contains(dp[n - 1][1], k))) {
    std::cout << "NO\n";
    return;
  }

  std::string ans;
  for (int i = n - 1; i >= 0; i--) {
    char c = contains(dp[i][0], k - (i == n - 1 ? 0 : (ans.back() != 'A')))
                 ? 'A'
                 : 'B';
    k -= (c != s[i]);
    if (i > 0) {
      k -= (s[i] != s[i - 1]);
    }
    if (i < n - 1) {
      k -= (c != ans.back());
    }
    ans += c;
  }

  std::reverse(ans.begin(), ans.end());
  std::cout << "YES\n" << ans << '\n';
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
