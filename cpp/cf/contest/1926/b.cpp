#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;

  std::vector<std::string> g;
  for (int i = 0; i < n; i++) {
    std::string s;
    std::cin >> s;
    g.push_back(s);
  }
  bool ok = false;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (g[i][j] == '1') {
        cnt++;
      }
    }
    if (cnt == 1) {
      ok = true;
    } else if (cnt > 1) {
      break;
    }
  }
  std::reverse(g.begin(), g.end());
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (g[i][j] == '1') {
        cnt++;
      }
    }
    if (cnt == 1) {
      ok = true;
    } else if (cnt > 1) {
      break;
    }
  }

  std::cout << (ok ? "TRIANGLE" : "SQUARE") << '\n';
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
