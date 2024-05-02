#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int k;
  std::cin >> k;
  std::string s;
  std::cin >> s;

  int n = s.size();
  std::stack<int> st;
  std::vector<int> cnt(n + 1);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      ans += st.size();
      st.push(i);
    } else {
      cnt[(i - st.top()) / 2]++;
      st.pop();
    }
  }
  for (int i = n; i >= 0; i--) {
    ll t = std::min(k, cnt[i]);
    ans -= t * i;
    k -= t;
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
