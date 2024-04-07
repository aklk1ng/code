#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;

  std::string mi = "zzz", cur;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      for (int k = 0; k < 26; k++) {
        if (i + j + k + 3 == n) {
          cur += char(i + 'a');
          cur += char(j + 'a');
          cur += char(k + 'a');
          mi = std::min(mi, cur);
        }
      }
    }
  }

  std::cout << mi << '\n';
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
