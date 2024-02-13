#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> p(n), l(n);
  for (int i = 0; i < n; i++) {
    std::cin >> p[i];
    p[i]--;
    l[p[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    if (l[i] == n - 1) {
      std::cout << rand() % n + 1 << (i == n - 1 ? '\n' : ' ');
    } else {
      std::cout << l[i] + 2 << (i == n - 1 ? '\n' : ' ');
    }
  }
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
