#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  int k = std::count(s.begin(), s.end(), '1');
  for (int i = 1 << k; i <= (1 << n) - (1 << (n - k)) + 1; i++) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
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
