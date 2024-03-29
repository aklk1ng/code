#include <bits/stdc++.h>
typedef long long ll;

std::vector<std::pair<int, int>> odd, even;

void init() {
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      if ((i + j) % 2) {
        odd.emplace_back(i, j);
      } else {
        even.emplace_back(i, j);
      }
    }
  }
}

void solve() {
  std::vector g(7, std::vector<int>(7));
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      char c;
      std::cin >> c;
      g[i][j] = (c == 'B');
    }
  }

  auto valid = [&](bool ok) {
    for (int r = 1; r < 6; r++) {
      for (int c = 1; c < 6; c++) {
        if (g[r][c] && ((r + c) % 2 == ok)) {
          if (g[r - 1][c - 1] && g[r - 1][c + 1] && g[r + 1][c - 1] &&
              g[r + 1][c + 1]) {
            return false;
          }
        }
      }
    }
    return true;
  };
  auto check = [&](auto self, int l, int idx,
                   std::vector<std::pair<int, int>> &v, int val) -> bool {
    if (l == 0) {
      return valid(val);
    }
    if (idx == v.size()) {
      return false;
    }
    bool ok = false;
    ok |= self(self, l, idx + 1, v, val);
    g[v[idx].first][v[idx].second] ^= 1;
    ok |= self(self, l - 1, idx + 1, v, val);
    g[v[idx].first][v[idx].second] ^= 1;
    return ok;
  };
  int ans = 0;
  for (int i = 0; i <= 4; i++) {
    if (check(check, i, 0, odd, 1)) {
      ans += i;
      break;
    }
  }
  for (int i = 0; i <= 4; i++) {
    if (check(check, i, 0, even, 0)) {
      ans += i;
      break;
    }
  }
  std::cout << ans << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  init();
  int T = 1;
  if (true) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
