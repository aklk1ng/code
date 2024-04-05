#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  std::vector a(4, std::vector<int>(2));
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      std::cin >> a[i][j];
    }
  }

  std::vector<int> p(4);
  for (int i = 0; i < 4; i++) {
    p[i] = a[i][0];
  }

  int x = *std::max_element(p.begin(), p.end()) - *std::min_element(p.begin(), p.end());
  std::cout << x * x << '\n';
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
