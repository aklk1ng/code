#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  std::string s;
  std::cin >> s;

  std::vector<int> v;
  for (auto &c : s) {
    v.push_back(c - '0');
  }
  int zeros = std::count(v.begin(), v.end(), 0);
  ll ans = 0;
  std::vector<int> cnt(2);
  for (auto &c : v) {
    cnt[c]++;
    if (!c) {
      ans += cnt[1] > 0 ? 1 : 0;
    } else {
      ans += zeros - cnt[0];
    }
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
