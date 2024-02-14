#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a;
  while (n) {
    int t = n, m = 0, p = 1;
    while (t) {
      if (t % 10) {
        m += p;
      }
      t /= 10;
      p *= 10;
    }
    a.push_back(m);
    n -= m;
  }
  std::cout << a.size() << '\n';
  std::sort(a.begin(), a.end());
  for (auto &e : a) {
    std::cout << e << ' ';
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
