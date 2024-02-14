#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::map<int, int> m;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    m[x]++;
  }
  int one = 0, two = 0;
  for (auto &[i, j] : m) {
    one += j == 1;
    two += j > 1;
  }
  std::cout << two + (one + 1) / 2 << '\n';
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
