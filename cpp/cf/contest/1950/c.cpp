#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int h, m;
  char c;
  std::cin >> h >> c >> m;
  std::string am = (h < 12 ? " AM" : " PM");
  h = (h % 12 ? h % 12 : 12);
  std::cout << (h < 10 ? "0" : "") << h << c << (m < 10 ? "0" : "") << m << am
            << '\n';
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
