#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int a, b, l;
  std::cin >> a >> b >> l;
  std::set<int> ans;
  for (int i = 0; i < 34; i++) {
    int x = l;
    bool ok = true;
    for (int _ = 0; _ < i; _++) {
      if (x % a) {
        ok = false;
        break;
      }
      x /= a;
    }
    if (!ok) {
      break;
    }
    while (true) {
      ans.insert(x);
      if (x % b) {
        break;
      }
      x /= b;
    }
  }
  std::cout << ans.size() << '\n';
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
