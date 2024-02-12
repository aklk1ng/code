#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  std::string b, b1, b2, e, e1, e2;
  std::cin >> b1 >> b2 >> e1 >> e2;
  std::swap(b2[0], b2[1]);
  std::swap(e2[0], e2[1]);
  b = b1 + b2;
  e = e1 + e2;
  b.erase(b.find('X'), 1);
  e.erase(e.find('X'), 1);
  if ((b + b).find(e) != std::string::npos) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
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
