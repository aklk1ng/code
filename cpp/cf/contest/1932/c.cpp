#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::string s;
  std::cin >> s;

  int l = 0, r = n - 1;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == 'L') {
      l++;
    } else {
      r--;
    }
  }
  std::vector<int> b(n);
  b[n - 1] = a[l] % m;

  for (int i = n - 2; i >= 0; i--) {
    if (s[i] == 'L') {
      b[i] = (b[i + 1] * a[--l]) % m;
    } else {
      b[i] = (b[i + 1] * a[++r]) % m;
    }
  }

  for (auto &e : b) {
    std::cout << e << ' ';
  }
  std::cout << '\n';
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
