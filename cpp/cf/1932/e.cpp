#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  std::reverse(s.begin(), s.end());
  std::vector<int> a(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    a[i] = a[i + 1] + (s[i] - '0');
  }

  std::string ans;
  int c = 0;
  for (int i = 0; i < n; i++) {
    c += a[i];
    ans += (char)(c % 10 + '0');
    c /= 10;
  }

  ans += (char)(c + '0');
  while (ans.back() == '0') {
    ans.pop_back();
  }
  std::reverse(ans.begin(), ans.end());
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
