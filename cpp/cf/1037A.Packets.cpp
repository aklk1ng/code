#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  int k = 1, z = 0;
  while (true) {
    if (n > 0) {
      z++;
    } else {
      break;
    }
    n -= k;
    k *= 2;
  }
  std::cout << z << '\n';
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
