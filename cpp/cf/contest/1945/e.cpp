#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, x;
  std::cin >> n >> x;
  std::vector<int> p(n);
  int t = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> p[i];
    if (p[i] == x) {
      t = i;
    }
  }

  int l = 0, r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (p[mid] <= x) {
      l = mid;
    } else {
      r = mid;
    }
  }

  std::cout << "1\n";
  std::cout << t + 1 << ' ' << l + 1 << '\n';
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
