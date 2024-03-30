#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int a, b, c;
  std::cin >> a >> b >> c;

  if (a < b && b < c) {
    std::cout << "STAIR\n";
  } else if (a < b && b > c) {
    std::cout << "PEAK\n";
  } else {
    std::cout << "NONE\n";
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
