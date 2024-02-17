#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::cout << n + 1 << '\n';
  int sum = 0;
  for (int i = n - 1; i >= 0; i--) {
    int add = (i - (a[i] + sum) % n + n) % n;
    std::cout << "1 " << i + 1 << ' ' << add << '\n';
    sum += add;
  }
  std::cout << "2 " << n << ' ' << n << '\n';
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
