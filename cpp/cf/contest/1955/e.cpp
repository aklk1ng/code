#include <bits/stdc++.h>
typedef long long ll;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  for (int k = n; k > 0; k--) {
    std::vector<char> t(n), end(n + 1);
    for (int i = 0; i < n; i++) {
      t[i] = s[i] - '0';
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt -= end[i];
      t[i] ^= cnt & 1;
      if (t[i] == 0) {
        if (i + k <= n) {
          end[i + k]++;
          cnt++;
          t[i] = 1;
        } else {
          break;
        }
      }
    }
    if (*std::min_element(t.begin(), t.end()) == 1) {
      std::cout << k << '\n';
      return;
    }
  }
  assert(false);
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
