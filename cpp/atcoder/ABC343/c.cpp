#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  ll n;
  std::cin >> n;

  auto isPalindrome = [&](ll num) {
    std::string s = std::to_string(num);
    std::string t = s;
    std::reverse(s.begin(), s.end());
    return t == s;
  };
  ll ans = 0;
  for (ll i = 1; i * i * i <= n; i++) {
    if (isPalindrome(i * i * i)) {
      ans = i * i * i;
    }
  }
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
