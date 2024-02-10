#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  std::string s;
  std::cin >> s;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') {
      continue;
    }
    int j = i + 1;
    while (j < n && s[j] != 'a') {
      j++;
    }
    for (int r = i; r < j; r++) {
      s[r]--;
    }
    std::cout << s << '\n';
    return;
  }
  s.back() = 'z';
  std::cout << s << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (false) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
