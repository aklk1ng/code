#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> p(n);
  for (int i = 0; i < n; i++) {
    std::cin >> p[i];
  }
  std::string s;
  std::cin >> s;

  auto sum = [&](std::vector<ll> &t, int l, int r) { return t[r + 1] - t[l]; };
  std::vector<ll> s1(n + 1), s2(n + 1);
  for (int i = 0; i < n; i++) {
    s1[i + 1] = s1[i] + (s[i] == 'B' ? p[i] : 0);
  }
  for (int i = 0; i < n; i++) {
    s2[i + 1] = s2[i] + p[i];
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans = std::max(ans, sum(s2, 0, i) - 2 * sum(s1, 0, i));
    ans = std::max(ans, sum(s2, i, n - 1) - 2 * sum(s1, i, n - 1));
  }
  ans += sum(s1, 0, n - 1);
  std::cout << ans << '\n';
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
