#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  int c = 1;
  while (n % c == 0) {
    c++;
  }
  std::string s;
  for (int i = 0; i < n; i++) {
    s += 'a' + (i % c);
  }
  std::cout << s << '\n';
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
