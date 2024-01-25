#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::set<int> s;
  s.insert(a[1]);
  bool ok = true;
  for (int i = 2; i <= n; i++) {
    int pre = a[i - 1];
    if (pre != a[i]) {
      if (pre < a[i]) {
        auto it = s.upper_bound(pre);
        if (it != s.end() && *it < a[i]) {
          ok = false;
          break;
        }
      } else {
        auto it = s.lower_bound(pre);
        if (it != s.begin() && *(--it) > a[i]) {
          ok = false;
          break;
        }
      }
    }
    s.insert(a[i]);
  }

  std::cout << (ok ? "YES" : "NO") << '\n';
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
