#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  std::string a, b;
  std::cin >> a >> b;

  bool f1 = false, f2 = false;
  if (a.size() == b.size()) {
    for (int i = 0; i < a.size(); i++) {
      if (a[i] == '1') {
        f1 = true;
      }
      if (b[i] == '1') {
        f2 = true;
      }
    }
  }
  if (a.size() == 1) {
    f1 = false;
  }
  if (a == b) {
    f1 = true;
    f2 = true;
  }
  std::cout << (f1 && f2 ? "YES" : "NO") << '\n';
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
