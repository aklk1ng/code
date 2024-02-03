#include <bits/stdc++.h>
typedef long long ll;

struct mq {
  std::stack<std::pair<ll, ll>> s1, s2;

  int size() { return s1.size() + s2.size(); }

  bool empty() { return this->size() == 0; }

  ll max() {
    if (this->empty()) {
      return LONG_MIN;
    }
    if (!s1.empty() && !s2.empty()) {
      return std::max(s1.top().second, s2.top().second);
    }
    if (!s1.empty()) {
      return s1.top().second;
    }
    return s2.top().second;
  }

  void push(ll val) {
    if (s2.empty()) {
      s2.push({val, val});
    } else {
      s2.push({val, std::max(val, s2.top().second)});
    }
  }

  void pop() {
    if (s1.empty()) {
      while (!s2.empty()) {
        if (s1.empty()) {
          s1.push({s2.top().first, s2.top().first});
        } else {
          s1.push({s2.top().first, std::max(s2.top().first, s1.top().second)});
        }
        s2.pop();
      }
    }
    s1.pop();
  }
};

void solve() {
  int n, k, x;
  std::cin >> n >> k >> x;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::vector<mq> q(x + 1);
  std::vector<std::queue<int>> pos(x + 1);
  std::vector dp(n + 1, std::vector<ll>(x + 1, LONG_MIN));
  dp[0][x] = 0;
  pos[x].push(-1);
  q[x].push(0);

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      while (!pos[j].empty() && pos[j].front() < i - k - 1) {
        q[j].pop();
        pos[j].pop();
      }
    }
    for (int j = 0; j < x; j++) {
      if (!q[j + 1].empty()) {
        dp[i][j] = std::max(dp[i][j], q[j + 1].max() + a[i - 1]);
        q[j].push(dp[i][j]);
        pos[j].push(i - 1);
      }
    }
  }

  ll ans = LONG_MIN;
  for (int i = n - k + 1; i <= n; i++) {
    ans = std::max(ans, *std::max_element(dp[i].begin(), dp[i].end()));
  }
  std::cout << (ans == LONG_MIN ? -1 : ans) << '\n';
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
