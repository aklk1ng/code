#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  std::string t;
  std::cin >> t;

  int a = std::count(t.begin(), t.end(), 'A');
  int b = std::count(t.begin(), t.end(), 'B');

  std::cout << (a > b ? 'A' : 'B') << '\n';
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
