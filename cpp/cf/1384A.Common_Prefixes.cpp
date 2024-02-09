#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::string s(200, 'a');
  std::cout << s << '\n';

  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    s[x] = s[x] == 'a' ? 'b' : 'a';
    std::cout << s << '\n';
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
