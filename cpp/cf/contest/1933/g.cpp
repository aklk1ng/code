#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m, q;
  std::cin >> n >> m >> q;
  bool b[8] = {1, 1, 1, 1, 1, 1, 1, 1};
  int ans = 8;
  std::cout << ans << '\n';
  while (q--) {
    int r, c;
    std::cin >> r >> c;
    std::string shape;
    std::cin >> shape;
    if ((r + (c + 1) / 2) % 2) {
      b[0] &= (shape == "circle");
      b[1] &= (shape == "square");
    } else {
      b[0] &= (shape == "square");
      b[1] &= (shape == "circle");
    }
    if ((r + c / 2) % 2) {
      b[2] &= (shape == "circle");
      b[3] &= (shape == "square");
    } else {
      b[2] &= (shape == "square");
      b[3] &= (shape == "circle");
    }

    if ((c + (r + 1) / 2) % 2) {
      b[4] &= (shape == "circle");
      b[5] &= (shape == "square");
    } else {
      b[4] &= (shape == "square");
      b[5] &= (shape == "circle");
    }
    if ((c + r / 2) % 2) {
      b[6] &= (shape == "circle");
      b[7] &= (shape == "square");
    } else {
      b[6] &= (shape == "square");
      b[7] &= (shape == "circle");
    }
    ans = 0;
    for (int i = 0; i < 8; i++) {
      ans += b[i];
    }
    std::cout << ans << '\n';
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
