#include <bits/stdc++.h>
typedef long long ll;
const int mod = 998244353;

void solve() {
  int n;
  ll k;
  std::cin >> n >> k;

  std::deque<ll> dq(n);
  for (int i = 0; i < n; i++) {
    std::cin >> dq[i];
  }

  while (dq.size() > 1 && k) {
    int mi = std::min(dq.front(), dq.back());
    if (k < 2 * mi) {
      dq.front() -= k / 2 + k % 2;
      dq.back() -= k / 2;
      k = 0;
    } else {
      dq.front() -= mi;
      dq.back() -= mi;
      k -= 2 * mi;
    }

    if (!dq.front()) {
      dq.pop_front();
    }
    if (!dq.back()) {
      dq.pop_back();
    }
  }

  int ans = n - dq.size();
  std::cout << ans + (dq.size() && dq.front() <= k) << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int t = 1;
  if (true) {
    std::cin >> t;
  }
  while (t--) {
    solve();
  }

  return 0;
}
