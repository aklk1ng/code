#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), f(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::deque<std::pair<int, int>> dq;
  int mx = 0;
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    f[a[i]]++;
    while (f[mx]) {
      mx++;
    }
    dq.push_back({mx, 1});
    sum += mx;
  }

  ll ans = sum;
  for (int i = 1; i < n; i++) {
    std::pair<int, int> me = {a[i], 0};
    sum -= dq.front().first;
    dq.front().second--;
    if (dq.front().second == 0) {
      dq.pop_front();
    }
    while (!dq.empty() && dq.back().first >= a[i]) {
      sum -= 1LL * dq.back().first * dq.back().second;
      me.second += dq.back().second;
      dq.pop_back();
    }
    dq.push_back(me);
    sum += 1LL * me.first * me.second;
    dq.push_back({n, 1});
    sum += n;
    ans = std::max(ans, sum);
  }

  std::cout << ans << '\n';
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
