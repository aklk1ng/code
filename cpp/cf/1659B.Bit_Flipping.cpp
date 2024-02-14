#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::string s;
  std::cin >> s;
  std::vector<int> f(n);
  int tmp = k;
  for (int i = 0; i < n && tmp > 0; i++) {
    if (k % 2 == s[i] - '0') {
      f[i] = 1;
      tmp--;
    }
  }
  f[n - 1] += tmp;
  for (int i = 0; i < n; i++) {
    if ((k - f[i]) % 2) {
      s[i] = '1' - (s[i] - '0');
    }
  }

  std::cout << s << '\n';
  for (auto &e : f) {
    std::cout << e << " \n"[e == f.back()];
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
