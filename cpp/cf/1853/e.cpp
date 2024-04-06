#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  int pre = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    x %= k;
    if (x > pre) {
      pq.push(x - pre);
      ans += pq.top();
      pq.pop();
    } else {
      pq.push(k + x - pre);
    }
    pre = x;
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
