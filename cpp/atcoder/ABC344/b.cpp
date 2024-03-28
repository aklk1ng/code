#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  std::vector<int> a;
  while (true) {
    int x;
    std::cin >> x;
    a.push_back(x);
    if (!x) {
      break;
    }
  }
  for (auto e = a.rbegin(); e != a.rend(); e++) {
    std::cout << *e << '\n';
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
