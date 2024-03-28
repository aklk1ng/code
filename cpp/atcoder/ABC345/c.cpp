#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  std::string s;
  std::cin >> s;

  std::vector<ll> cnt(26);
  bool same = false;
  ll n = s.size();
  for (int i = 0; i < n; i++){
    cnt[((int)(s[i] - 'a'))]++;
  }
  ll ans = n * n;
  for (int i = 0; i < 26; i++) {
    ans -= cnt[i] * cnt[i];
    if (cnt[i] > 1) {
      same = true;
    }
  }
  ans /= 2;
  if (same) {
    ans++;
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
